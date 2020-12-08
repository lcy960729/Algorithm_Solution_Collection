//
// Created by LeeChanYoung on 2020/11/19.
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

int N, M, R;
int board[101][101];
bool visited[101][101] = {};

//E, S, W, N
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int dir[27];

int score = 0;

void dfs(int y, int x, int d) {
    score++;

    for (int i = 1; i < board[y][x]; i++) {
        int ny = y + dy[d] * i;
        int nx = x + dx[d] * i;

        if (ny < 1 || ny > N || nx < 1 || nx > M)
            continue;

        if (visited[ny][nx])
            continue;

        visited[ny][nx] = true;
        dfs(ny, nx, d);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    dir['E' - 'A'] = 0;
    dir['S' - 'A'] = 1;
    dir['W' - 'A'] = 2;
    dir['N' - 'A'] = 3;

    while (R--) {
        int y, x;
        char d;

        cin >> y >> x >> d;
        visited[y][x] = true;
        dfs(y, x, dir[d - 'A']);

        cin >> y >> x;
        visited[y][x] = false;
    }

    cout << score << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << (visited[i][j] ? 'F' : 'S') << " ";
        }
        cout << "\n";
    }
}