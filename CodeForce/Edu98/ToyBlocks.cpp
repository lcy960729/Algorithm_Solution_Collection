//
// Created by LeeChanYoung on 2020/12/14.
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

        vector<ll> a(n);
        ll sum = 0;
        ll mx = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }

        if (n == 2) {
            cout << 0 << endl;
        }else{
            ll int s = mx*(n-1) - sum;
            if (s >= 0) {
                cout << s << "\n";
            }else{
                if (abs(s) % (n - 1) == 0) {
                    cout << 0 << "\n";
                } else {
                    cout << (n - 1) - abs(s) % (n - 1) << "\n";
                }
            }
        }
    }
}