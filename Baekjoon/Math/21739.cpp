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

const int MOD = 1e9 + 7;

int N;

ll pow1(ll x, ll n) {
    ll extra = 1;

    while (n > 1) {
        if (n & 1) {
            extra = (extra * x) % MOD;
        }
        x = (x * x) % MOD;
        n = n >> 1;
    }

    return (x * extra) % MOD;
}

int catalanNumber() {
    unsigned ll ret = 1;

    int n = 2 * N;
    int r = N;

    if (n < r)
        swap(n, r);

    for (int i = 0; i < r; ++i) {
        ret = (ret * (n - i)) % MOD;
        ret = (ret * pow1(i + 1, MOD - 2)) % MOD;
    }

    ret = (ret * pow1(N + 1, MOD - 2)) % MOD;
    return ret % MOD;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int ans = catalanNumber();
    cout << ans << '\n';
}