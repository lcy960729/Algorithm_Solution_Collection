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
        int n;
        cin >> n;

        vector<int> sum_r(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int val;
            cin >> val;

            sum_r[i + 1] = sum_r[i] + val;
        }

        int m;
        cin >> m;

        vector<int> sum_b(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            int val;
            cin >> val;

            sum_b[i + 1] = sum_b[i] + val;
        }

        cout << *max_element(sum_r.begin(), sum_r.end()) + *max_element(sum_b.begin(), sum_b.end()) << '\n';
    }
}
