//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>

#define pii pair<int, int>
#define ll long long

using namespace std;

int n;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int map[501][501] = {};
int memo[501][501];

int dfs(pii now) {
    int result = 1;

    if (memo[now.first][now.second] != -1) {
        return memo[now.first][now.second];
    }

    for (int i = 0; i < 4; i++) {
        int nextX = now.first + dx[i];
        int nextY = now.second + dy[i];

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
            continue;

        if (map[nextX][nextY] > map[now.first][now.second]) {
            result = max(result, dfs({nextX, nextY}) + 1);
        }
    }

    memo[now.first][now.second] = result;
    return result;
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

    memset(memo, -1, sizeof(memo));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs({i, j}));
        }
    }

    cout << ans;
}