//
// Created by LeeChanYoung on 2020/11/30.
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

int t;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;

        int ans = max(n - r, r - 1) + max(m - c, c - 1);
        cout << ans << "\n";
    }
}