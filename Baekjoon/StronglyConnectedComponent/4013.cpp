#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n, m, s, p;
int id, sn;
vector<int> discovered;
vector<int> sccid;
vector<int> money;
vector<bool> restaurant;
vector<vector<int>> g;
vector<vector<int>> SCC;
stack<int> st;

int dfs(int cur) {
    int parent = discovered[cur] = ++id;
    st.push(cur);

    for (int next : g[cur]) {
        if (discovered[next] == -1) {
            parent = min(parent, dfs(next));
        } else if (sccid[next] == -1) {
            parent = min(parent, discovered[next]);
        }
    }

    if (parent == discovered[cur]) {
        vector<int> scc;
        while (true) {
            int t = st.top();
            st.pop();
            scc.push_back(t);

            sccid[t] = sn;

            if (t == cur) break;
        }
        SCC.push_back(scc);
        sn++;
    }

    return parent;
}

int topologicalSort() {
    int s2;
    vector<vector<int>> g2(SCC.size());
    vector<int> money2(SCC.size());
    vector<bool> restaurant2(SCC.size());
    vector<int> indegree(SCC.size());

    for (int i = 0; i < n; ++i) {
        int sid = sccid[i];
        money2[sid] += money[i];
        if (restaurant[i]) restaurant2[sid] = true;
        if (i == s) s2 = sid;

        for (int next : g[i]) {
            if (sid == sccid[next])
                continue;

            g2[sid].push_back(sccid[next]);
            indegree[sccid[next]]++;
        }
    }

    vector<bool> check(SCC.size(), false);
    vector<int> totalMoney(SCC.size());
    queue<int> q;

    check[s2] = true;

    for (int i = 0; i < SCC.size(); ++i) {
        totalMoney[i] = money2[i];
        if (indegree[i] == 0) q.push(i);
    }

    for (int i = 0; i < SCC.size(); ++i) {
        int cur = q.front();
        q.pop();

        for (int next : g2[cur]) {
            if (check[cur]) {
                totalMoney[next] = max(totalMoney[next], totalMoney[cur] + money2[next]);
                check[next] = true;
            }

            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < SCC.size(); ++i) {
        if (restaurant2[i] && check[i]) ret = max(ret, totalMoney[i]);
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

    discovered.assign(n, -1);
    sccid.assign(n, -1);
    money.assign(n, 0);
    restaurant.assign(n, false);
    g.assign(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
    }

    for (int i = 0; i < n; ++i) {
        cin >> money[i];
    }

    cin >> s >> p;
    s--;
    for (int i = 0; i < p; ++i) {
        int r;
        cin >> r;
        restaurant[--r] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (discovered[i] == -1) dfs(i);
    }

    cout << topologicalSort();
}