#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n, m, s, e;
vector<vector<pii>> g;
vector<vector<pii>> r_g;
vector<int> cost;
vector<int> indegree;

bool visited[10001][10001] = {};

int dfs(int e) {
    int ret = 0;

    queue<int> q;
    q.push(e);
    visited[0][e] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (pii next : r_g[cur]) {
            if (cost[cur] - next.second != cost[next.first])
                continue;

            if (visited[cur][next.first])
                continue;

            ret++;
            visited[cur][next.first] = true;
            q.push(next.first);
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

    cin >> n >> m;

    g.assign(n + 1, vector<pii >());
    r_g.assign(n + 1, vector<pii >());
    cost.assign(n + 1, 0);
    indegree.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        r_g[v].push_back({u, w});

        indegree[v]++;
    }

    cin >> s >> e;

    queue<pii > q;
    q.push({s, 0});

    for (int i = 0; i < n; ++i) {
        int cur = q.front().first;
        int c = q.front().second;
        q.pop();

        for (pii next : g[cur]) {
            cost[next.first] = max(cost[next.first], c + next.second);

            if (--indegree[next.first] == 0) {
                q.push({next.first, cost[next.first]});
            }
        }
    }

    cout << cost[e] << '\n' << dfs(e);
}