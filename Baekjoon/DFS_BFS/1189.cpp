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

int R, C, K;

vector<vector<int>> visited;
vector<vector<char>> board;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int dfs(int y, int x, int dist) {
    if (dist == K) {
        return (y == 0 && x == C - 1) ? 1 : 0;
    }

    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
            continue;
        }

        if (visited[ny][nx] || board[ny][nx] == 'T') continue;

        visited[ny][nx] = true;
        ret += dfs(ny, nx, dist + 1);
        visited[ny][nx] = false;
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> K;

    board.assign(R, vector<char>(C, false));
    visited.assign(R, vector<int>(C));

    for (auto &i : board) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    visited[R-1][0] = true;
    cout << dfs(R - 1, 0, 1) << '\n';
}