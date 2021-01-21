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

int N, M;
int cost[3];
pii start;

struct Edge {
    int w;
    int y;
    int x;
    int f;
};

struct Node {
    int w;
    int y;
    int x;
    int s;

    bool operator<(const Node &n) const {
        return this->w > n.w;
    }
};

vector<Edge> g[51][51];

int dist[51][51][16];
bool fin[51][51][16];

void dijk(pii start) {
    memset(fin, false, sizeof(fin));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fill(dist[i][j], dist[i][j] + 16, 1e9);

    int sy = start.first;
    int sx = start.second;

    priority_queue<Node> pq;
    pq.push({0, sy, sx, 0});
    dist[sy][sx][0] = 0;

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        int y = now.y;
        int x = now.x;
        int s = now.s;
        int w = now.w;

        if (fin[y][x][s])
            continue;

        if (s == (1 << M) - 1) {
            cout << w << '\n';
            break;
        }

        for (Edge next : g[y][x]) {
            int nw = next.w;
            int ny = next.y;
            int nx = next.x;
            int nf = next.f;
            int ns = s;

            if (nf != -1) {
                ns |= (1 << nf);
            }

            if (dist[ny][nx][ns] > dist[y][x][s] + nw) {
                dist[ny][nx][ns] = dist[y][x][s] + nw;

                pq.push({dist[ny][nx][ns], ny, nx, ns});
            }
        }

        fin[y][x][s] = true;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> cost[0] >> cost[1] >> cost[2] >> start.second >> start.first >> M;

    int lake[51][51];
    memset(lake, -1, sizeof(lake));

    for (int i = 0; i < M; ++i) {
        int y, x;
        cin >> y >> x;

        lake[y][x] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 8; ++k) {
                int dy[] = {-2, -1, -2, -1, 1, 2, 1, 2};
                int dx[] = {-1, -2, 1, 2, -2, -1, 2, 1};

                int nextY = i + dy[k];
                int nextX = j + dx[k];
                int weight = cost[0];

                if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                    continue;

                g[i][j].push_back({weight, nextY, nextX, lake[nextY][nextX]});
            }

            for (int k = 0; k < 8; ++k) {
                int dy[] = {-1, 1, -1, 1, -1, 1, 0, 0};
                int dx[] = {-1, -1, 1, 1, 0, 0, 1, -1};

                for (int l = 1; l < N; ++l) {
                    int nextY = i + dy[k] * l;
                    int nextX = j + dx[k] * l;
                    int weight = cost[(k / 4) + 1];

                    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N)
                        break;

                    g[i][j].push_back({weight, nextY, nextX, lake[nextY][nextX]});
                }
            }
        }
    }

    dijk(start);
}