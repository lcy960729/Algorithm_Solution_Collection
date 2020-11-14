//
// Created by CY on 2020-09-09.
//

//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int n, m;
int map[301][301] = {};
bool visited[301][301] = {};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(pii start) {
    queue<pii > q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = now.first + dx[i];
            int nextY = now.second + dy[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;

            if (!visited[nextX][nextY] && map[nextX][nextY] == 0 && map[now.first][now.second] > 0)
                map[now.first][now.second]--;

            if (visited[nextX][nextY] || map[nextX][nextY] == 0) {
                continue;
            }

            q.push({nextX, nextY});
            visited[nextX][nextY] = true;
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

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int setCount = 0;
    int year = 0;

    while (setCount < 2){
        year++;
        setCount = 0;

        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (visited[i][j] || map[i][j] == 0)
                    continue;

                setCount++;
                bfs({i, j});
            }
        }

        if (setCount == 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    cout << year-1;
}