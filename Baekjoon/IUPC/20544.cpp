#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;


const int mod = 1000000007;
int N;
ll memo[1001][3][3][2];

int dp(int cur, int preHeight, int count, bool catus) {
    if (cur == N) {
        if (catus)
            return 1;
        else
            return 0;
    }

    ll &ret = memo[cur][preHeight][count][catus];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (count == 2) {
        ret += dp(cur + 1, 0, 0, catus) % mod;
    } else {
        ret += dp(cur + 1, 0, 0, catus) % mod;
        ret += dp(cur + 1, 1, count + 1, catus) % mod;
        if (preHeight != 2)
            ret += dp(cur + 1, 2, count + 1, true) % mod;
    }

    return ret %= mod;
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

    cout << dp(1, 0, 0, false);
}