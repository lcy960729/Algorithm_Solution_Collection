//
// Created by CY on 2020-10-19.
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
int memo[101][10][1024];

int dp(int length, int cur, int selected) {
    if (length == N) {
        return selected == (1 << 10) - 1 ? 1 : 0;
    }

    int &ret = memo[length][cur][selected];
    if (ret != -1)
        return ret;

    ret = 0;
    if (cur != 0) {
        ret += dp(length + 1, cur - 1, selected | 1 << (cur - 1));
    }

    if (cur != 9) {
        ret += dp(length + 1, cur + 1, selected | 1 << (cur + 1));
    }

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

    cin >> N;

    memset(memo, -1, sizeof(memo));

    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp(1, i, 1 << i);
        ans %= 1000000000;
    }

    cout << ans << "\n";
}