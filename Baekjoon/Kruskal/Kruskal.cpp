//
// Created by lcy96 on 2020-10-01.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n, m;

int parent[1001];
vector<pii> g[1001];
int dist[1001];
bool visited[1001];

struct Edge {
    int u, v, w;

    Edge() {
        u = -1;
        v = -1;
        w = 0;
    }

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    bool operator<(const Edge &O) const {
        return w < O.w;
    }
};

int find(int id) {
    if (parent[id] < 0) {
        return id;
    }

    parent[id] = find(parent[id]);
    return parent[id];
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

void dijk(int start) {
    fill(dist, dist + 1001, 1e9);
    memset(visited, false, sizeof(visited));

    priority_queue<pii > pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int nowNode = pq.top().second;
        pq.pop();

        if (visited[nowNode])
            continue;

        for (pii next : g[nowNode]) {
            int nextNode = next.first;
            int weight = next.second;

            if (dist[nextNode] > dist[nowNode] + weight) {
                dist[nextNode] = dist[nowNode] + weight;

                pq.push({-dist[nextNode], nextNode});
            }
        }

        visited[nowNode] = true;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<Edge> edge;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    sort(edge.begin(), edge.end());

    int result = 0, cnt = 0;
    memset(parent, -1, sizeof(parent));


    for (int i = 0;; i++) {
        if (uni(edge[i].u, edge[i].v)) {
            int u = edge[i].u;
            int v = edge[i].v;
            int w = edge[i].w;

            g[u].push_back({v, w});
            g[v].push_back({u, w});

            result += edge[i].w;
            if (++cnt == n - 1)
                break;
        }
    }

    bool selected[1001] = {};
    int arr[3];
    for (int i = 0; i < 3; i++) {
        int d;
        cin >> d;
        selected[d] = true;
        arr[i] = d;
    }

    int temp = 1e9;

    for (int i = 1; i <= n; i++) {

        dijk(i);

        temp = min({temp, dist[arr[0]] + dist[arr[1]] + dist[arr[2]]});
    }

    cout << temp << endl;
}