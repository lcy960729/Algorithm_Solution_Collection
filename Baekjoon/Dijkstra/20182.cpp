//
// Created by LeeChanYoung on 2020/11/19.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M, A, B;
ll C;
vector<pii > g[100001];
ll dist[100001];

struct Node {
    ll cost;
    int index;

    bool operator<(const Node &n1) const {
        return this->cost < n1.cost;
    }
};

bool dijk(int s, ll limit) {
    fill(dist, dist + N + 1, LL_MAX);

    priority_queue<Node> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        int curNode = cur.index;
        pq.pop();

        if (dist[curNode] != -cur.cost)
            continue;

        for (pii next : g[cur.index]) {
            int nextNode = next.first;
            int weight = next.second;

            if (dist[curNode] + weight > C || weight > limit)
                continue;

            if (dist[nextNode] > dist[curNode] + weight) {
                dist[nextNode] = dist[curNode] + weight;
                pq.push({-dist[nextNode], nextNode});
            }
        }
    }

    return dist[B] != LL_MAX;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> A >> B >> C;

    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        g[s].push_back({e, c});
        g[e].push_back({s, c});
    }

    int left = 0, right = 1e9+1, mid;

    while (left + 1 < right) {
        mid = (left + right) / 2;

        if (dijk(A, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (right == 1e9+1)
        cout << -1;
    else
        cout << right;
}