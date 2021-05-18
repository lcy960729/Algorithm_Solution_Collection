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

int n, m;
// 서 북 동 남
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int walls[51][51] = {};
vector<vector<int>> visited(51, vector<int>(51, -1));

vector<int> rooms;

void bfs(int y, int x) {
    queue<pii > q;
    q.push({y, x});
    visited[y][x] = rooms.size();

    int ret = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        ret++;

        for (int i = 0; i < 4; ++i) {
            if (walls[cur.first][cur.second] & (1 << i))
                continue;

            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (visited[ny][nx] != -1) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second];
        }
    }

    rooms.push_back(ret);
}

int bfs2() {
    vector<vector<bool>> visited2(51, vector<bool>(51, false));

    queue<pii > q;
    q.push({0, 0});
    visited2[0][0] = true;

    int result = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (visited2[ny][nx]) continue;

            int curRoom = visited[cur.first][cur.second];
            int nextRoom = visited[ny][nx];

            if (curRoom != nextRoom) {
                result = max(result, rooms[curRoom] + rooms[nextRoom]);
            }

            q.push({ny, nx});
            visited2[ny][nx] = true;
        }
    }

    return result;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> walls[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] != -1) continue;

            bfs(i, j);
        }
    }

    cout << rooms.size() << '\n'
         << *max_element(rooms.begin(), rooms.end()) << '\n'
         << bfs2() << '\n';
}