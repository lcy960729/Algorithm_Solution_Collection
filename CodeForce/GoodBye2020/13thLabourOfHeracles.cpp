//
// Created by LeeChanYoung on 2020/12/31.
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

        vector<int> w(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> w[i];
        }
        vector<int> deg(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;

            deg[u]++;
            deg[v]++;
        }

        ll ans = 0;
        vector<int> to_sort;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < deg[i]; ++j) {
                to_sort.push_back(w[i]);
            }
            ans += w[i];
        }

        sort(to_sort.begin(), to_sort.end(), greater<>());

        cout << ans << " ";
        for (auto &i : to_sort) {
            ans += i;
            cout << ans << " ";
        }
        cout << '\n';
    }
}
