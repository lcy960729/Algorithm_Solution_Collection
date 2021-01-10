//
// Created by LeeChanYoung on 2020/12/30.
//
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

        vector<pii > p(n);
        for (auto &i : p) {
            cin >> i.first >> i.second;
        }

        vector<bool> check(n, false);
        for (int i = n/2; i < n; ++i) {
            check[i] = true;
        }

        double ans = 1e9;
        do {
            double x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if (check[i]) {
                    x += p[i].first;
                    y += p[i].second;
                } else {
                    x -= p[i].first;
                    y -= p[i].second;
                }
            }
            ans = min(ans, sqrt(x * x + y * y));
        } while (next_permutation(check.begin(), check.end()));


        cout << fixed;
        cout.precision(12);
        cout << ans << '\n';
    }
}
