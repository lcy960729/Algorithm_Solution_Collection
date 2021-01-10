#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

#define MAX_NODE 40001
#define MAX_DEPTH 21

using namespace std;

vector<pii > g[MAX_NODE];
bool visited[MAX_NODE];
int d[MAX_NODE];
int parent[MAX_NODE][MAX_DEPTH];
int costArr[MAX_NODE];

void dfs(int cur, int cost, int depth) {
    d[cur] = depth;
    costArr[cur] = cost;
    for (pii next : g[cur]) {
        if (visited[next.first])
            continue;

        visited[cur] = true;
        parent[next.first][0] = cur;
        dfs(next.first, cost + next.second, depth + 1);
    }
}

void f(int n) {
    for (int j = 1; j < MAX_DEPTH; ++j) {
        for (int i = 1; i <= n; ++i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);

    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if (d[y] - d[x] >= (1 << i)) {
            y = parent[y][i];
        }
    }

    if (x == y) return x;

    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
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
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    visited[1] = true;
    dfs(1, 0, 0);
    f(n);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        int l = lca(a, b);

        int ret = costArr[a] + costArr[b] - costArr[l] * 2;

        cout << ret << '\n';
    }
}