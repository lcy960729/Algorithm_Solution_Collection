#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

vector<pii > g[100001];
int dist[100001];

void dijk(int start) {
    priority_queue<pii > pq;

    dist[start] = 0;
    pq.push({0, start});

    bool finished[100001] = {};

    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();

        if (finished[now])
            continue;

        for (pii x : g[now]) {
            int nxt = x.second, w = x.first;

            if (dist[nxt] > dist[now] + w) {
                dist[nxt] = dist[now] + w;
                pq.push({-dist[nxt], nxt});
            }
        }
        finished[now] = true;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int v, e, k;
    cin >> v >> e >> k;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
    }

    fill(dist, dist + v + 1, 1e9);

    dijk(k);

    for (int i = 1; i <= v; i++) {
        if (dist[i] == 1e9) {
            cout << "INF" << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
}