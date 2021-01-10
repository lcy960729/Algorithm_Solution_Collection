//
// Created by LeeChanYoung on 2020/12/31.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <unordered_set>

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
        string s;
        cin >> s;

        char a = '?', b = '?';
        int ans = 0;

        for (auto &c : s) {
            if (c == a || c == b) {
                ans++;
                c = '?';
            }
            a = b;
            b = c;
        }

        cout << ans << '\n';
    }
}

