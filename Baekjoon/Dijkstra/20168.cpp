//
// Created by LeeChanYoung on 2020/11/19.
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

int N, M, A, B, C;
vector<pii > g[100001];
int dist[100001];
bool finished[100001];

void dijk(int s, int limit) {
    fill(dist, dist + N + 1, 1e9);

    priority_queue<pii > pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        pii cur = pq.top();
        int curNode = cur.second;
        pq.pop();

        if (dist[curNode] != -cur.first)
            continue;

        for (pii next : g[cur.second]) {
            int nextNode = next.first;
            int weight = next.second;

            if (dist[nextNode] > dist[curNode] + weight) {

                if (dist[curNode] + weight > C)
                    continue;

                if (weight > limit)
                    continue;

                dist[nextNode] = dist[curNode] + weight;
                pq.push({-dist[nextNode], nextNode});
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

    cin >> N >> M >> A >> B >> C;

    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        g[s].push_back({e, c});
        g[e].push_back({s, c});
    }

    int left = 1, right = 1e9, mid;

    while (left + 1 < right) {
        mid = (left + right) / 2;

        dijk(A, mid);

        if (dist[B] != 1e9) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (right == 1e9)
        cout << -1;
    else
        cout << right;
}