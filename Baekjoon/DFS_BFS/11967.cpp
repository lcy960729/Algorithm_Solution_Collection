#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int M;
initializer_list<LNode> N;
vector<vector<int>> board;
map<pii, vector<pii>> switches;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        x--;
        y--;
        a--;
        b--;

        switches[{y, x}].push_back({b, a});
    }

    vector<vector<int>> visited(N, vector<int>(N, -1));

    queue<pii > q;
    q.push({0, 0});
    visited[0][0] = 1;
    board[0][0] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (pii sw : switches[cur]) {
            board[sw.first][sw.second] = 1;

            if (visited[sw.first][sw.second] == 0) {
                q.push(sw);
            }
        }

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (visited[ny][nx] == 1) continue;

            if (board[ny][nx] == 0) {
                visited[ny][nx] = 0;
            } else if (board[ny][nx] == 1) {
                q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }

    int ans = 0;
    for (auto &i : board) {
        for (auto &j : i) {
            if (j == 1) ans++;
        }
    }
    cout << ans << '\n';
}