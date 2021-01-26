#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Node {
    int y, x, cost;
};

struct Edge {
    int cost, y, x, state;

    bool operator<(const Edge &edge) const {
        return this->cost > edge.cost;
    }
};

int N, A, B, C, M;
pii start;
int feed[51][51];

vector<Node> g[51][51];

bool isOk(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N)
        return false;
    else
        return true;
}

void dijk(pii start) {
    int dist[51][51][16];
    bool fin[51][51][16];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fill(dist[i][j], dist[i][j] + 16, 1e9);
        }
    }
    memset(fin, false, sizeof(fin));

    priority_queue<Edge> pq;
    pq.push({0, start.second, start.first, 0});
    dist[start.second][start.first][0] = 0;

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (cur.state == (1 << M) - 1) {
            cout << cur.cost << "\n";
            break;
        }

        for (Node next : g[cur.y][cur.x]) {
            int ns = cur.state;

            if (feed[next.y][next.x] > 0) {
                ns |= (1 << (feed[next.y][next.x] - 1));
            }

            if (dist[next.y][next.x][ns] > dist[cur.y][cur.x][cur.state] + next.cost) {
                dist[next.y][next.x][ns] = dist[cur.y][cur.x][cur.state] + next.cost;
                pq.push({dist[next.y][next.x][ns], next.y, next.x, ns});
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

    cin >> N >> A >> B >> C >> start.first >> start.second >> M;

    for (int i = 1; i <= M; ++i) {
        int x, y;
        cin >> x >> y;

        feed[y][x] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 나이트 경로
            int dy1[] = {-1, -2, -2, -1, 1, 2, 2, 1};
            int dx1[] = {-2, -1, 1, 2, 2, 1, -1, -2};
            for (int k = 0; k < 8; ++k) {
                int ny = i + dy1[k];
                int nx = j + dx1[k];

                if (!isOk(ny, nx))
                    continue;

                g[i][j].push_back({ny, nx, A});
            }

            //비숍
            int dy2[] = {-1, -1, 1, 1, 0, 1, 0, -1};
            int dx2[] = {-1, 1, 1, -1, -1, 0, 1, 0};

            for (int k = 0; k < 8; ++k) {
                for (int l = 1; l < N; ++l) {
                    int ny = i + dy2[k] * l;
                    int nx = j + dx2[k] * l;

                    if (!isOk(ny, nx))
                        continue;

                    g[i][j].push_back({ny, nx, k < 4 ? B : C});
                }
            }
        }
    }


    dijk(start);
}