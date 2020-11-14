//
// Created by CY on 2020-10-19.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;
int map[1001][1001];
int cost[1001][1001][3];

bool visited[1001][1001];

int dy[] = {0, 1, 0};
int dx[] = {-1, 0, 1};

int dfs(int curY, int curX, int dir) {
    if (curY == N && curX == M) {
        return map[curY][curX];
    }

    int &ret = cost[curY][curX][dir];
    if (ret != -987654321)
        return ret;

    visited[curY][curX] = true;
    for (int i = 0; i < 3; i++) {
        int nextY = curY + dy[i];
        int nextX = curX + dx[i];

        if (nextX < 1 || nextX > M || nextY < 1 || nextY > N)
            continue;

        if (visited[nextY][nextX])
            continue;

        ret = max(ret, dfs(nextY, nextX, i));
    }

    visited[curY][curX] = false;

    ret += map[curY][curX];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];

            fill(cost[i][j], cost[i][j] + 3, -987654321);
        }
    }

    cout << dfs(1, 1, 0) << "\n";
}
