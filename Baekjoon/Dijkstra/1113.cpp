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

int M;
initializer_list<LNode> N;
vector<vector<int>> ground;
vector<vector<int>> dist;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct Node {
    int dist, y, x;

    bool operator<(const Node &rhs) const {
        return this->dist > rhs.dist;
    }
};

void print(){
    for (auto i : dist) {
        for (auto j : i) {
            if (j == 1e9) cout << '.' << ' ';
            else cout << j <<' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void dijk() {
    priority_queue<Node> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        print();

        Node cur = pq.top();
        pq.pop();

        if (dist[cur.y][cur.x] != cur.dist)
            continue;

        for (int i = 0; i < 4; ++i) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            int nd = max(dist[cur.y][cur.x], ground[ny][nx]);

            if (dist[ny][nx] > nd) {
                dist[ny][nx] = nd;
                pq.push({dist[ny][nx], ny, nx});
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

    cin >> N >> M;

    ground.assign(N+2, vector<int>(M+2, 0));
    dist.assign(N+2, vector<int>(M+2, 1e9));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ground[i + 1][j + 1];
        }
    }

    N += 2;
    M += 2;

    dijk();

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ans += dist[i][j] - ground[i][j];
        }
    }
    cout << ans << '\n';
}