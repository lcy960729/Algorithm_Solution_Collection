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

int parent[10001];

struct Edge {
    int u, v;
    ll w;

    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

int find(int id) {
    if (parent[id] < 0)
        return id;

    return parent[id] = find(parent[id]);
}

bool uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return false;

    parent[parentA] += parent[parentB];
    parent[parentB] = parentA;

    return true;
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

    vector<Edge> edge(e);
    for (int i = 0; i < e; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge.begin(), edge.end());

    memset(parent, -1, sizeof(parent));

    ll ans = 0;

    int cnt = 0;
    for (int i = 0; i < e; i++) {
        if (uni(edge[i].u, edge[i].v)) {
            ans += edge[i].w;

            if (++cnt == v-1)
                break;
        }
    }

    cout << ans << "\n";
}