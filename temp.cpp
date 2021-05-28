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

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N, M;
int mx = 0, mn = 1e9;
vector<vector<int>> ground;
vector<vector<int>> water;
vector<vector<bool>> visited;

void bfs(int y, int x, int h) {
    queue<pii > q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        water[cur.first][cur.second]--;

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx]) continue;

            if (ground[ny][nx] + water[ny][nx] == h && water[ny][nx] > 0) {
                q.push({ny, nx});
                visited[ny][nx] = true;
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

    ground.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < M; ++j) {
            ground[i][j] = s[j] - '0';

            mx = max(mx, ground[i][j]);
            mn = min(mn, ground[i][j]);
        }
    }

    water.assign(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            water[i][j] = mx - ground[i][j];
        }
    }

    for (int h = mx; h > mn; --h) {
        visited.assign(N, vector<bool>(M, false));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (water[i][j] <= 0 || visited[i][j]) continue;

                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if ((ny < 0 || ny >= N || nx < 0 || nx >= M) ||
                        ground[ny][nx] + water[ny][nx] < ground[i][j] + water[i][j]) {
                        bfs(i, j, h);
                        break;
                    }
                }
            }
        }

    }

    int ans = 0;
    for (auto &i : water) {
        for (auto &j : i) {
            ans += j;
        }
    }

    cout << ans << '\n';
}