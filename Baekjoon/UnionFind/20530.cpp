//
// Created by LeeChanYoung on 2021/01/04.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[200001];

int find(int id) {
    if (parent[id] < 0) {
        return id;
    }

    return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    parent[parentA] += parent[parentB];
    parent[parentB] = parentA;
}

int visited[200001];
bool fin[200001] = {};
vector<int> cyclePath;
bool isCycleNode[200001] = {};

void saveCyclePath(int cur, int next) {
    cyclePath.push_back(cur);
    isCycleNode[cur] = true;

    if (cur == next)
        return;

    saveCyclePath(visited[cur], next);
}

void dfs(int cur, int pre, const vector<vector<int>> &g) {
    for (int next : g[cur]) {
        if (pre == next)
            continue;

        if (visited[next] == -1) {
            visited[next] = cur;
            dfs(next, cur, g);
        } else if (!fin[next]) {
            saveCyclePath(cur, next);
        }
    }

    fin[cur] = true;
}

void uniGraph(int cur, int pre, int p, const vector<vector<int>> &g) {
    for (int next : g[cur]) {
        if (next == pre || isCycleNode[next])
            continue;

        uni(p, next);

        if (g[next].size() > 1) {
            uniGraph(next, cur, p, g);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    memset(visited, -1, sizeof(visited));

    for (int i = 1; i <= n; ++i) {
        if (visited[i] != -1)
            continue;

        visited[i] = i;
        dfs(i, 0, g);
    }

    for (int cur : cyclePath) {
        uniGraph(cur, 0, cur, g);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        cout << (find(u) == find(v) ? 1 : 2) << '\n';
    }
}