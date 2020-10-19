//
// Created by CY on 2020-09-11.
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

int n, m, k;
int s, d;

int dist[1001][1001] = {};
vector<pii > g[1001];

struct node {
    int weight;
    int now;
    int count;
};

struct cmp {
    bool operator()(node n1, node n2) {
        return n1.weight > n2.weight;
    }
};

void dijk() {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, s, 0});
    dist[s][0] = 0;

    while (!pq.empty()) {
        int nowNode = pq.top().now;
        int count = pq.top().count;
        int nowWeight = pq.top().weight;
        pq.pop();

        bool shorter = false;
        for (int i = 0; i < count; i++){
            if (dist[nowNode][i] < -nowWeight) {
                shorter = true;
                break;
            }
        }

        if (shorter || count >= n || -nowWeight > dist[nowNode][count])
            continue;

        for (pii next : g[nowNode]) {
            int nextNode = next.first;
            int weight = next.second;

            if (count + 1 <= n && dist[nextNode][count + 1] > dist[nowNode][count] + weight) {
                dist[nextNode][count + 1] = dist[nowNode][count] + weight;

                pq.push({-dist[nextNode][count + 1], nextNode, count + 1});
            }
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

    cin >> n >> m >> k;

    cin >> s >> d;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    for (int i = 0; i <= n; i++) {
        fill(dist[i], dist[i] + 1001, 1e9);
    }

    dijk();

    for (int i = 0; i <= k; i++) {
        int p = 0;

        if (i != 0)
            cin >> p;

        int ans = 1e9;
        for (int j = 0; j <= n; j++) {
            if (dist[d][j] == 1e9)
                continue;

            dist[d][j] += j * p;
            ans = min(ans, dist[d][j]);

        }
        cout << ans << "\n";
    }
}
