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

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, -1));

    queue<pii > q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                q.push({i, j});
                visited[i][j] = 0;
            }
        }
    }

    int ans = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            if (visited[ny][nx] != -1)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second] + 1;

            ans = max(ans, visited[ny][nx]);
        }
    }

    cout << ans << '\n';
}