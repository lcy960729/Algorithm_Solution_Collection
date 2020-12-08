//
// Created by LeeChanYoung on 2020/11/29.
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
int board[101][101];
bool visited[101][101][101][4] = {};

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct status {
    int y, x, dir, speed, time;
};

bool isGoing(int dir, int y, int x, int speed, int time) {
    int ny = y;
    int nx = x;

    for (int i = 0; i < speed; ++i) {
        nx += dx[dir];
        ny += dy[dir];

        if (i == speed - 1) {
            time++;
        }

        if (board[ny][nx] != 0 && board[ny][nx] <= time) {
            return false;
        }
    }

    return true;
}

void bfs() {
    queue<status> q;
    q.push({0, 0, -1, 0, 0});
    visited[0][0][0][0] = false;

    while (!q.empty()) {
        status cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;
        int speed = cur.speed;
        int time = cur.time;

        if (y == N - 1 && x == N - 1) {
            cout << time;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nSpeed = (i == dir ? speed : 1);

            int ny = cur.y + dy[i] * nSpeed;
            int nx = cur.x + dx[i] * nSpeed;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;

            if (visited[ny][nx][nSpeed + 1][i])
                continue;

            if (!isGoing(i, y, x, nSpeed, time)) {
                continue;
            }

            visited[ny][nx][nSpeed + 1][i] = true;
            q.push({ny, nx, i, nSpeed + 1, time + 1});
        }
    }

    cout << "Fired";
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
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    bfs();
}