#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int t;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> colors(n);
        for (ll i = 0; i < n; ++i) {
            cin >> colors[i];
        }

        ll mn = LL_MAX;
        for (ll cur_color = 1; cur_color <= 100; ++cur_color) {
            ll i = 0;
            ll cnt = 0;

            while (i < n) {
                if (colors[i] == cur_color) {
                    ++i;
                } else {
                    ++cnt;
                    i += k;
                }
            }
            mn = min(cnt, mn);
        }
        cout << mn << '\n';
    }
}