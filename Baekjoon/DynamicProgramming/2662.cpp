//
// Created by CY on 2020-10-05.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;

int company[301][21];
int memo[301][21];
int invested[301][21];

int dp(int investment, int companyNum) {
    if (companyNum > M)
        return 0;

    int &ret = memo[investment][companyNum];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i <= investment; i++) {
        int temp = company[i][companyNum] + dp(investment - i, companyNum + 1);
        if (ret < temp) {
            ret = temp;
            invested[investment][companyNum] = i;
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int investment;
        cin >> investment;

        for (int j = 0; j < M; j++) {
            cin >> company[investment][j];
        }
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(N, 0) << "\n";

    int totalInvest = N;
    for (int i = 0; i < M; i++) {
        cout << invested[totalInvest][i] << " ";
        totalInvest -= invested[totalInvest][i];
    }
}