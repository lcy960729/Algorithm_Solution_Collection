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

        vector<int> check(2*n+2, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            check[x]++;
        }

        int ans = 0;
        for (int i = 1; i < check.size(); ++i) {
            if (check[i] != 0) ans++;

            if (check[i] > 1) {
                check[i + 1]++;
                check[i]--;
            }
        }

        cout << ans << "\n";
    }
}