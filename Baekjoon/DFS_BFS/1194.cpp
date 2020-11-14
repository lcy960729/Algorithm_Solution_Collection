//
// Created by CY on 2020-10-06.
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
char map[51][51];
bool visited[64][51][51] = {};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct st {
    int key, y, x, cnt;
};

int bfs(pii start) {
    queue<st> q;
    q.push({0, start.first, start.second, 0});
    visited[0][start.first][start.second] = true;

    while (!q.empty()) {
        st cur = q.front();
        q.pop();

        int cnt = cur.cnt;

        if (map[cur.y][cur.x] == '1') {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            int nextKey = cur.key;

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;

            if (visited[nextKey][nextY][nextX])
                continue;

            if (map[nextY][nextX] == '#') {
                continue;
            }else if ('A' <= map[nextY][nextX] && map[nextY][nextX] <= 'F') {
                int keyIndex = (map[nextY][nextX] - 'A');

                if ((nextKey & (1 << keyIndex)) == 0)
                    continue;
            } else if ('a' <= map[nextY][nextX] && map[nextY][nextX] <= 'f') {
                int keyIndex = (map[nextY][nextX] - 'a');
                nextKey |= (1 << keyIndex);
            }

            q.push({nextKey, nextY, nextX, cnt+1});
            visited[nextKey][nextY][nextX] = true;
        }

    }

    return -1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    pii start;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j];

            if (map[i][j] == '0') {
                start = {i, j};
            }
        }
    }

    cout << bfs(start);
}