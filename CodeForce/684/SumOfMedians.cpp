//
// Created by LeeChanYoung on 2020/12/18.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <deque>

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
        int n, k;
        cin >> n >> k;

        vector<int> a(n * k + 1);
        for (int i = 1; i <= n * k; i++) {
            cin >> a[i];
        }

        ll m = round(n / 2.0) - 1;
        m = n - m;

        ll index = n * k + 1;
        ll ans = 0;
        while (k--) {
            index -= m;
            if (index <= 0)
                break;
            ans += a[index];
        }

        cout << ans << "\n";
    }
}
