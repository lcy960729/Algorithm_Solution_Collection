//
// Created by LeeChanYoung on 2020/12/07.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            vector<int> b;
            set<int> set1;

            bool check = true;
            int m = a.size() - i + 1;
            for (int j = 0; j <= n - i; j++) {
                int mn = 1e9;

                for (int k = 0; k < i; k++) {
                    mn = min(mn, a[j + k]);
                }

                if (mn > m || set1.find(mn) != set1.end()) {
                    check = false;
                    break;
                }

                b.push_back(mn);
                set1.insert(mn);
            }

            cout << (check ? 1 : 0);
        }
        cout << "\n";
    }
}