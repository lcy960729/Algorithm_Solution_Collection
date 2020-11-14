//
// Created by lcy96 on 2020-09-30.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
char board[101][101];
bool visited[101][101] = {};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int y, int x, bool isColorWeakness) {
    queue<pii > q;
    q.push({y, x});
    visited[y][x] = true;

    char standardColor = board[y][x];

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (visited[ny][nx])
                continue;

            if (isColorWeakness) {
                if ((standardColor != 'B' && board[ny][nx] == 'B') || (standardColor == 'B' && board[ny][nx] != 'B'))
                    continue;
            } else {
                if (standardColor != board[ny][nx])
                    continue;
            }

            q.push({ny, nx});
            visited[ny][nx] = true;
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

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < N; ++j) {
            board[i][j] = str[j];
        }
    }

    int ans[2] = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])
                continue;
            ans[0]++;
            bfs(i, j, false);
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j])
                continue;
            ans[1]++;
            bfs(i, j, true);
        }
    }
    cout << ans[0] << " " << ans[1];
}