#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define MAX_SIZE 500

using namespace std;

vector<vector<pii>> node(501, vector<pii >(10000, {0, 0}));
vector<vector<pii>> r_node(501, vector<pii >(10000, {0, 0}));

int dist[MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int N, M, S, D;

void dijk() {
    fill(dist, dist + MAX_SIZE, 1e9);

    bool fin[MAX_SIZE] = {};

    priority_queue<pii > pq;
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int nowNode = pq.top().second;
        pq.pop();

        if (fin[nowNode])
            continue;

        for (pii next : node[nowNode]) {
            int nextNode = next.first;
            int weight = next.second;

            if (visited[nowNode][nextNode])
                continue;

            if (dist[nextNode] > dist[nowNode] + weight) {
                dist[nextNode] = dist[nowNode] + weight;

                pq.push({-dist[nextNode], nextNode});
            }
        }

        fin[nowNode] = true;
    }
}

void bfs() {
    bool bfsVistied[MAX_SIZE] = {};

    queue<int> q;
    q.push(D);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == S)
            continue;

        for (pii next : r_node[now]) {
            int nextNode = next.first;

            if (dist[now] == dist[nextNode] + next.second) {
                visited[nextNode][now] = true;

                if (!bfsVistied[nextNode]) {
                    bfsVistied[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        for (int i = 0; i < MAX_SIZE; i++) {
            node[i].clear();
            r_node[i].clear();
        }
        memset(visited, false, sizeof(visited));

        cin >> N >> M;

        if (N + M == 0)
            return 0;

        cin >> S >> D;

        for (int i = 0; i < M; i++) {
            int U, V, P;
            cin >> U >> V >> P;

            node[U].push_back({V, P});
            r_node[V].push_back({U, P});
        }

        dijk();
        bfs();
        dijk();

        if (dist[D] == 1e9)
            cout << -1 << "\n";
        else
            cout << dist[D] << "\n";
    }
}