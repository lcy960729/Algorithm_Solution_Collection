//
// Created by LeeChanYoung on 2020/12/12.
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
        int n, m;
        cin >> n >> m;

        vector<int> a(n+1, 0);
        int index = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];

            if (a[i] != i)
                index = i;
        }

        double ans = 1;
        while (m--) {
            int r;
            double p;
            cin >> r >> p;

            if (r < index || index == 0)
                continue;

            ans *= (1.0 - p);
        }

        cout << fixed;
        cout.precision(6);
        cout << (index == 0 ? ans : 1.0 - ans) << "\n";
    }
}