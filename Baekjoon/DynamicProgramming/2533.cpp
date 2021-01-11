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

vector<vector<int>> g(1000001, vector<int>());
int memo[1000001][2];

int dp(int cur, int parent, int isParentEarlyAdopter) {
    int &ret = memo[cur][isParentEarlyAdopter];
    if (ret != -1) {
        return ret;
    }

    ret = isParentEarlyAdopter;
    for (int next : g[cur]) {
        if (next == parent) continue;

        if (isParentEarlyAdopter) {
            ret += min(dp(next, cur, 0), dp(next, cur, 1));
        } else {
            ret += dp(next, cur, 1);
        }
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(memo, -1, sizeof(memo));
    cout << min(dp(1,0, 0), dp(1,0, 1)) << "\n";
}