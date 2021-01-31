//
// Created by LeeChanYoung on 2021/01/30.
//

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
#define MAX 10001

using namespace std;

int id, d[MAX];
bool fin[MAX];
vector<int> g[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x) {
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];

        if (d[y] == 0)
            parent = min(parent, dfs(y));
        else if (!fin[y])
            parent = min(parent, d[y]);
    }

    if (parent == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();

            scc.push_back(t);
            fin[t] = true;

            if (t == x) break;
        }
        sort(scc.begin(), scc.end());

        SCC.push_back(scc);
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

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
    }

    for (int i = 1; i <= v; ++i) {
        if (d[i] == 0) dfs(i);
    }

    sort(SCC.begin(), SCC.end());

    cout << SCC.size() << '\n';
    for (int i = 0; i < SCC.size(); ++i) {
        for (int j = 0; j < SCC[i].size(); ++j) {
            cout << SCC[i][j] << ' ';
        }
        cout << "-1\n";
    }
}