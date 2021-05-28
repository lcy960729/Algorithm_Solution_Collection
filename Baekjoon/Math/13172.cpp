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

const int MOD = 1000000007;

ll gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll powMOD(ll x, ll n) {
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M;
    cin >> M;

    ll ans = 0;
    while (M--) {
        int n, s;
        cin >> n >> s;
x
        int g = gcd(n, s);
        n /= g;
        s /= g;

        ll inv = powMOD(n, MOD - 2);

        ans += s * inv % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}