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

    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;

    if (k < l || k > r) {
        cout << "NO";
    }

    if (x > y) {
        if (k + y > r)
            k -= x, t--;

        if (k < l) {
            cout << "NO";
            return 0;
        }

        ll canAlive = (k - l) / (x - y);
        if (canAlive < t) {
            cout << "NO";
            return 0;
        }

        cout << "Yes";
    } else {
        vector<bool> was(x, false);
        while (t > 0) {
            if (was[k % x]) {
                cout << "Yes";
                return 0;
            }

            was[k % x] = true;
            ll canMove = min(t, (k - l) / x);
            k -= canMove * x;
            t -= canMove;

            if (t == 0) {
                cout << "Yes";
                return 0;
            }
            t--;

            if (k + y <= r) {
                k += y;
            }

            k -= x;
            if (k < l || k > r) {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
}