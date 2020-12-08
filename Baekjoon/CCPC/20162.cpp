//
// Created by LeeChanYoung on 2020/12/02.
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

int N;
int arr[1001];
int memo[1001][1001];

int dp(int cur, int maxIndex) {
    if (cur == N+1) {
        return 0;
    }

    int &ret = memo[cur][maxIndex];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (arr[maxIndex] < arr[cur]) {
        ret = dp(cur + 1, cur) + arr[cur];
    }
    ret = max(ret, dp(cur + 1, maxIndex));

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(1, 0);
}
