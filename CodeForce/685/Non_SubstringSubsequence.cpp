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
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        while (q--) {
            int l, r;
            cin >> l >> r;

            --l, --r;

            bool ans = true;
            for (int i = 0; i < l && ans; i++) {
                if (s[i] == s[l]) ans = false;
            }

            for (int i = r + 1; i < n && ans; i++) {
                if (s[i] == s[r]) ans = false;
            }

            cout << (ans ? "NO" : "YES") << "\n";
        }
    }
}
