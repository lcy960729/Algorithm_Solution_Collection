//
// Created by LeeChanYoung on 2020/12/30.
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
        int n, k;
        cin >> n >> k;

        vector<int> h(n);
        for (auto &i : h) {
            cin >> i;
        }

        bool check = true;
        int mn = h[0];
        int mx = h[0];

        for (int i = 1; i < n; ++i) {
            mn = max(mn - k + 1, h[i]);
            mx = min(mx + k - 1, h[i] + k - 1);
            if (mn > mx) {
                check = false;
                break;
            }
        }

        if (mx < h[n-1] || h[n-1] < mn)
            check = false;

        cout << (check ? "YES\n" : "NO\n");
    }
}

