//
// Created by lcy96 on 2020-10-21.
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

int t, n, k;

int memo[101][101][2];

int dp(int len, int count, int preBit) {
    if (len == n) {
        if (count == k)
            return 1;
        else
            return 0;
    }

    int &ret = memo[len][count][preBit];

    if (ret != -1)
        return ret;

    ret = dp(len + 1, count, 0) + dp(len + 1, count + preBit * 1, 1);

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;


    while (t--) {
        cin >> n >> k;

        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0, 0) << "\n";
    }
}