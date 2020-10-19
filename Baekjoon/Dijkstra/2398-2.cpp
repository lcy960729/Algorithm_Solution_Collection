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

vector<pii> g[1001];
int dist[3][1001];
int path[3][1001];

vector<pii> answer;

void dijk(int start, int dist[], int path[]) {
    bool visited[1001] = {};
    fill(dist, dist + 1001, 1e9);

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

                path[nextNode] = nowNode;
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

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int person[3];
    for (int i = 0; i < 3; i++) {
        int d;
        cin >> d;
        person[i] = d;
    }

    for (int i = 0; i < 3; i++){
        dijk(person[i], dist[i], path[i]);
    }

    int minimumCost = 1e9;
    int destination;
    for (int i = 1; i <= n; i++){
        if (minimumCost > dist[0][i] + dist[1][i] + dist[2][i]){
            minimumCost = dist[0][i] + dist[1][i] + dist[2][i];
            destination = i;
        }
    }

    for (int i = 0; i < 3; i++){
        for(int k = destination; path[i][k] != 0; k = path[i][k]){
            answer.emplace_back(k, path[i][k]);
        }
    }

    cout << minimumCost << " " << answer.size() << "\n";
    for (pii x : answer){
        cout << x.first << " " << x.second << "\n";
    }
}