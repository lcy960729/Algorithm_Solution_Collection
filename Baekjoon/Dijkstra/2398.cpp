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
int dist[1001];
bool visited[1001];
int path[1001];

vector<pii> answer;
void dfs(int cur, int destination){
    if (cur == destination) {
        return;
    }

    dfs(path[cur], destination);

    int begin = path[cur];
    int end = cur;

    if (begin > end) swap(begin, end);
    answer.push_back({begin, end});
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

    int index[3];
    for (int i = 0; i < 3; i++) {
        int d;
        cin >> d;
        index[i] = d;
    }

    int minimumCost = 1e9;
    int answerIndex = 0;
    for (int i = 1; i <= n; i++) {
        dijk(i);

        int sumCost = dist[index[0]] + dist[index[1]] + dist[index[2]];

        if (minimumCost > sumCost){
            minimumCost = sumCost;
            answerIndex = i;
        }
    }

    dijk(answerIndex);

    for (int i : index){
        dfs(i, answerIndex);
    }

    cout << minimumCost << " " << answer.size() << "\n";
    for (pii x : answer){
        cout << x.first << " " << x.second << "\n";
    }
}