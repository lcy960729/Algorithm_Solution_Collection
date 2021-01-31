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
#define MAX 2001

using namespace std;

int n, m, id, SN;
vector<int> d, sn;
vector<vector<int>> g;
vector<vector<int>> SCC;
stack<int> s;

int oppo(int n) {
    return n % 2 ? n - 1 : n + 1;
}

int dfs(int cur) {
    int parent = d[cur] = ++id;
    s.push(cur);

    for (int next : g[cur]) {
        if (d[next] == -1)
            parent = min(parent, dfs(next));
        else if (sn[next] == -1)
            parent = min(parent, d[next]);
    }

    if (parent == d[cur]) {
        vector<int> scc;
        while (true) {
            int t = s.top();
            s.pop();
            scc.push_back(t);

            sn[t] = SN;
            if (t == cur) break;
        }
        SCC.push_back(scc);
        SN++;
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

    while (cin >> n >> m) {
        id = SN = 0;
        d.clear();
        sn.clear();
        g.clear();
        SCC.clear();
        while (!s.empty()) s.pop();

        d.assign(n * 2 + 1, -1);
        sn.assign(n * 2 + 1, -1);
        g.assign(n * 2 + 1, vector<int>());

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;

            a = (a < 0 ? -a * 2 - 2 : a * 2 - 1);
            b = (b < 0 ? -b * 2 - 2 : b * 2 - 1);

            g[oppo(a)].push_back(b);
            g[oppo(b)].push_back(a);
        }

        g[0].push_back(1);

        for (int i = 0; i < n * 2; ++i) {
            if (d[i] == -1) dfs(i);
        }

        bool isOk = true;
        for (int i = 0; i < n; ++i) {
            if (sn[i * 2] == sn[i * 2 + 1]) {
                isOk = false;
                break;
            }
        }

        cout << (isOk ? "yes\n" : "no\n");
    }
}