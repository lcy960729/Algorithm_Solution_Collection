//
// Created by LeeChanYoung on 2020/12/18.
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
        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;

        string s;
        cin >> s;

        int ans = 0;
        for (char c : s) {
            if (c == '0') {
                ans += min(c0, c1 + t);
            } else {
                ans += min(c1, c0 + t);
            }
        }

        cout << ans << "\n";
    }
}