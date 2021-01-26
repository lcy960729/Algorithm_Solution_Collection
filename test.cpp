#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

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

    int n, k;
    cin >> n >> k;

    vector<pii > c(k);
    int mx = 0;
    for (int i = 0; i < c.size(); ++i) {
        cin >> c[i].first;
        c[i].second = i + 1;
        mx = max(mx, c[i].first);
    }

    if (mx > (n + 1) / 2) {
        cout << -1;
        return 0;
    }

    sort(c.rbegin(), c.rend());

    int index = 0;
    vector<int> ans(n);
    for (int i = 0; i < c.size(); ++i) {
        for (int j = 0; j < c[i].first; ++j) {
            ans[index] = c[i].second;
            index += 2;

            if (index >= n)
                index = 1;
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }
}