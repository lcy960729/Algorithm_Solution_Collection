//
// Created by LeeChanYoung on 2020/12/09.
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
int m[101];
int c[101];

int memo[101][100001];

int dp(int cur, int totalCost) {
    if (cur >= N)
        return 0;

    int &ret = memo[cur][totalCost];
    if (ret != -1)
        return ret;

    ret = dp(cur + 1, totalCost);
    if (c[cur] <= totalCost){
        ret = max(ret, dp(cur + 1, totalCost - c[cur]) + m[cur]);
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

    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }

    memset(memo, -1, sizeof(memo));

    int totalCost = 0;
    while (true) {
        if (dp(0, totalCost) >= M) {
            cout << totalCost << endl;
            break;
        }
        totalCost++;
    }
}