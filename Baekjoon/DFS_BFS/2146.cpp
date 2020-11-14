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
#define ppii pair<pair<int, int>, int>

#define ll long long

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;

int map[101][101];
int visited[101][101];
int setCount = 0;

void bfs(pii start) {
    queue<pii > q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pii now = q.front();
        q.pop();

        map[now.first][now.second] = setCount;

        for (int i = 0; i < 4; i++) {
            int nextX = now.first + dx[i];
            int nextY = now.second + dy[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;

            if (visited[nextX][nextY] != -1 || map[nextX][nextY] == 0)
                continue;

            q.push({nextX, nextY});
            visited[nextX][nextY] = visited[now.first][now.second] + 1;
        }
    }
}

int bfsFindShortPath(pii start) {
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    int setId = map[start.first][start.second];

    int result = 1e9;
    while (!q.empty()) {
        pii now = q.front();

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = now.first + dx[i];
            int nextY = now.second + dy[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;

            if (visited[nextX][nextY] != -1)
                continue;

            if (map[nextX][nextY] != 0 && setId != map[nextX][nextY]){
                result = min(result, visited[now.first][now.second]);
                continue;
            }

            q.push({nextX, nextY});

            if (map[nextX][nextY] == 0){
                visited[nextX][nextY] = visited[now.first][now.second] + 1;
            }else{
                visited[nextX][nextY] = 0;
            }
        }
    }

    return result;
}

void printMap() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));

    queue<pii> setList;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] != -1 || map[i][j] == 0)
                continue;

            setCount++;
            setList.push({i, j});
            bfs({i, j});
        }
    }

    int ans = 1e9;
    while(!setList.empty()) {
        memset(visited, -1, sizeof(visited));

        ans = min(ans, bfsFindShortPath(setList.front()));
        setList.pop();
    }

    cout << ans;
}
