//
// Created by lcy96 on 2020-10-01.
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

int N, M;
int map[51][51];
int totalSpace = 0;
int ans = 1e9;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

queue<pii > q;
int visited[51][51];

int bfs() {
    int result = 0;
    int filledSpace = 0;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        filledSpace++;
        result = max(result, visited[cur.first][cur.second]);

        if (filledSpace == totalSpace) {
            return result;
        }

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (visited[ny][nx] != -1 || map[ny][nx] == 1)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second] + 1;
        }
    }

    return 1e9;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pii > possibleSpace;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0)
                totalSpace++;
            else if (map[i][j] == 2) {
                possibleSpace.emplace_back(i, j);
                totalSpace++;
            }
        }
    }

    vector<bool> pick;
    for (int i = 0; i < possibleSpace.size() - M; i++) {
        pick.push_back(false);
    }

    for (int i = 0; i < M; i++) {
        pick.push_back(true);
    }

    do {
        memset(visited, -1, sizeof(visited));

        for (int i = 0; i < pick.size(); i++) {
            if (pick[i]) {
                int y = possibleSpace[i].first;
                int x = possibleSpace[i].second;

                q.push({y, x});
                visited[y][x] = 0;
            }
        }

        ans = min(ans, bfs());

    } while (next_permutation(pick.begin(), pick.end()));

    if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans;
    }
}