#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n, m, id, sn;
vector<vector<int>> g;
vector<vector<int>> SCC;
vector<int> discovered;
vector<int> sccId;
stack<int> st;

int dfs(int cur) {
    int parent = discovered[cur] = ++id;
    st.push(cur);

    for (int next : g[cur]) {
        if (discovered[next] == -1) {
            parent = min(parent, dfs(next));
        } else if (sccId[next] == -1) {
            parent = min(parent, discovered[next]);
        }
    }

    if (parent == discovered[cur]) {
        vector<int> scc;
        while (true) {
            int t = st.top();
            st.pop();
            scc.push_back(t);

            sccId[t] = sn;

            if (t == cur) break;
        }
        SCC.push_back(scc);
        sn++;
    }

    return parent;
}

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
        id = sn = 0;
        g.clear();
        SCC.clear();
        discovered.clear();
        sccId.clear();
        while(!st.empty()) st.pop();

        cin >> n >> m;

        g.assign(n, vector<int>());
        discovered.assign(n, -1);
        sccId.assign(n, -1);

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            g[--x].push_back(--y);
        }

        for (int i = 0; i < n; ++i) {
            if (discovered[i] == -1)
                dfs(i);
        }

        vector<int> indegree(SCC.size());
        for (int i = 0; i < n; ++i) {
            for(int next : g[i]){
                if (sccId[i] == sccId[next])
                    continue;

                indegree[sccId[next]]++;
            }
        }

        int ans = 0;
        for (int i : indegree){
            if (i == 0)
                ans++;
        }

        cout << ans << '\n';
    }
}
