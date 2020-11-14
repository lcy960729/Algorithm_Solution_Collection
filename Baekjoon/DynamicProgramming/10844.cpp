//
// Created by lcy96 on 2020-09-29.
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

int memo[10][101];

int dp(int pre, int length) {
    if (length == 1) {
        return 1;
    }

    int &ret = memo[pre][length];
    if (ret != -1)
        return ret;

    ret = 0;
    if (pre < 9)
        ret += dp(pre + 1, length - 1) % 1000000000;

    if (pre > 0)
        ret += dp(pre - 1, length - 1) % 1000000000;

    ret %= 1000000000;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> N;

    int ans = 0;
    for (int i = 1; i < 10; i++) {
        ans += dp(i, N) % 1000000000;
        ans %= 1000000000;
    }
    cout << ans;
}