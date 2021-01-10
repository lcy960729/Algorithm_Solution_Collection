//
// Created by LeeChanYoung on 2020/12/16.
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
        int x;
        cin >> x;

        if (x < 10) {
            cout << x << "\n";
        } else if (x > 45) {
            cout << -1 << "\n";
        } else {
            int ans = 0;
            if (x < 18) {
                ans += 89 - ((17 - x) * 10);
            } else if (x < 25) {
                ans += 789 - ((24 - x) * 100);
            } else if (x < 31) {
                ans += 6789 - ((30 - x) * 1000);
            } else if (x < 36) {
                ans += 56789 - ((35 - x) * 10000);
            } else if (x < 40) {
                ans += 456789 - ((39 - x) * 100000);
            } else if (x < 43) {
                ans += 3456789 - ((42 - x) * 1000000);
            } else if (x < 45) {
                ans += 23456789 - ((44 - x) * 10000000);
            } else if (x == 45) {
                ans += 123456789;
            }
            cout << ans << "\n";
        }
    }
}