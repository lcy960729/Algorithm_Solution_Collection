//
// Created by LeeChanYoung on 2020/12/18.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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
        ll x, y;
        cin >> x >> y;

        ll z = (ll) sqrt(y - x);

        if (y - x == z * z) {
            cout << 2 * z - 1;
        } else if (z * z < y - x && y - x <= z * z + z) {
            cout << 2 * z;
        } else if (z * z + z < y - x && y - x < (z + 1) * (z + 1)) {
            cout << 2 * z + 1;
        }
        cout << "\n";
    }
}
