//
// Created by LeeChanYoung on 2020/12/01.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX LL_MAX
#define LL_MAX 3e18

using namespace std;

vector<pii > g[10001];
ll dist[10001];
bool fin[10001] = {};

void dijk(int start) {
    fill(dist, dist + 10001, LL_MAX);
    memset(fin, false, sizeof(fin));

    priority_queue<pii > pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (fin[cur])
            continue;

        for (pii next : g[cur]) {
            int nextNode = next.first;
            int weight = next.second;

            if (dist[nextNode] > dist[cur] + weight) {
                dist[nextNode] = dist[cur] + weight;
                pq.push({-dist[nextNode], nextNode});
            }
        }

        fin[cur] = true;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int store[10] = {};
    ll time[10] = {};

    int lastIndex = 0;
    cin >> store[0];
    for (int i = 1; i < 10; ++i) {
        cin >> store[i];

        dijk(store[lastIndex]);

        if (dist[store[i]] == LL_MAX)
            continue;

        time[i] = time[lastIndex] + dist[store[i]];
        lastIndex = i;
    }

    int start;
    cin >> start;
    dijk(start);

    vector<int> ans;
    for (int i = 0; i < 10; i++) {
        if (time[i] == 0 && i != 0)
            continue;

        if (dist[store[i]] <= time[i]) {
            ans.push_back(store[i]);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty())
        cout << -1;
    else
        cout << ans[0];
}