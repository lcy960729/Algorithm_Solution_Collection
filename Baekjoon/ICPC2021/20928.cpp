#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define pll pair<ll, ll>
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

    int n, m;
    cin >> n >> m;

    vector<ll> p(n, 0);
    for (auto &i : p) {
        cin >> i;
    }

    vector<ll> x(n, 0);
    for (auto &i : x) {
        cin >> i;
    }

    int ans = 0;

    int cur = 0;
    while (p[cur] + x[cur] < m) {
        int next = -1;

        for (int i = cur + 1; i < n && p[cur] + x[cur] >= p[i]; ++i) {
            int id = next == -1 ? cur : next;

            if (p[id] + x[id] < p[i] + x[i]) {
                next = i;
            }
        }

        if (next == -1 || (next == n - 1 && p[next] + x[next] < m)) {
            ans = -1;
            break;
        }

        ans++;
        cur = next;
    }

    cout << ans << '\n';
}