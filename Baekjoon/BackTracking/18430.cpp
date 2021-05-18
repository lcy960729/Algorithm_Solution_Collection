#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;
vector<vector<bool>> visited;
vector<vector<int>> board;

int getMaxStrength(int y, int x) {
    y += (x == M ? 1 : 0);
    x %= M;

    if (y < 0 || y >= N || x < 0 || x >= M)
        return 0;

    int ret = getMaxStrength(y, x + 1);
    if (y + 1 >= 0 && y + 1 < N && x + 1 >= 0 && x + 1 < M) {
        if (!visited[y + 1][x] && !visited[y][x] && !visited[y][x + 1]) {
            visited[y + 1][x] = true;
            visited[y][x] = true;
            visited[y][x + 1] = true;
            ret = max(ret, getMaxStrength(y, x + 1) + (board[y][x] * 2 + board[y + 1][x] + board[y][x + 1]));
            visited[y + 1][x] = false;
            visited[y][x] = false;
            visited[y][x + 1] = false;
        }
    }

    if (y + 1 >= 0 && y + 1 < N && x - 1 >= 0 && x - 1 < M) {
        if (!visited[y + 1][x] && !visited[y][x] && !visited[y][x - 1]) {
            visited[y + 1][x] = true;
            visited[y][x] = true;
            visited[y][x - 1] = true;
            ret = max(ret, getMaxStrength(y, x + 1) + (board[y][x] * 2 + board[y + 1][x] + board[y][x - 1]));
            visited[y + 1][x] = false;
            visited[y][x] = false;
            visited[y][x - 1] = false;
        }
    }

    if (y - 1 >= 0 && y - 1 < N && x + 1 >= 0 && x + 1 < M) {
        if (!visited[y - 1][x] && !visited[y][x] && !visited[y][x + 1]) {
            visited[y - 1][x] = true;
            visited[y][x] = true;
            visited[y][x + 1] = true;
            ret = max(ret, getMaxStrength(y, x + 1) + (board[y][x] * 2 + board[y - 1][x] + board[y][x + 1]));
            visited[y - 1][x] = false;
            visited[y][x] = false;
            visited[y][x + 1] = false;
        }
    }

    if (y - 1 >= 0 && y - 1 < N && x - 1 >= 0 && x - 1 < M) {
        if (!visited[y - 1][x] && !visited[y][x] && !visited[y][x - 1]) {
            visited[y - 1][x] = true;
            visited[y][x] = true;
            visited[y][x - 1] = true;
            ret = max(ret, getMaxStrength(y, x + 1) + (board[y][x] * 2 + board[y - 1][x] + board[y][x - 1]));
            visited[y - 1][x] = false;
            visited[y][x] = false;
            visited[y][x - 1] = false;
        }
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

    cin >> N >> M;

    board.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));

    for (auto &i : board) {
        for (auto &j: i) {
            cin >> j;
        }
    }

    cout << getMaxStrength(0, 0) << '\n';
}