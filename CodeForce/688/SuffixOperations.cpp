//
// Created by LeeChanYoung on 2020/12/06.
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

vector<int> a;
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;


    while (t--) {
        int n;
        cin >> n;

        a.resize(sizeof(int) * (n+1));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        ll ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans += abs(a[i] - a[i - 1]);
        }

        int mx = max(abs(a[2] - a[1]), abs(a[n] - a[n - 1]));
        for (int i = 2; i < n; i++) {
            mx = max(mx,
                     abs(a[i] - a[i - 1]) +
                     abs(a[i + 1] - a[i]) -
                     abs(a[i + 1] - a[i - 1]));
        }
        cout << ans - mx << "\n";
    }
}