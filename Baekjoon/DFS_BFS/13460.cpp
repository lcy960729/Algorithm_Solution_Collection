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

int N, M;

struct state {
    int depth;
    pii red;
    pii blue;
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int ans = -1;

pii hole;
char board[11][11];
bool visited[11][11][11][11];
queue<state> q;

void move(int &y, int &x, int i) {
    while (true) {
        y += dy[i];
        x += dx[i];

        if (board[y][x] == '#') {
            y -= dy[i];
            x -= dx[i];
            break;
        } else if (board[y][x] == 'O') {
            break;
        }
    }
}

void bfs(state s) {
    q.push(s);
    visited[s.red.first][s.red.second][s.blue.first][s.blue.second] = true;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.depth > 10)
            break;

        if (cur.red.first == hole.first && cur.red.second == hole.second) {
            ans = cur.depth;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int red_ny = cur.red.first;
            int red_nx = cur.red.second;
            int blue_ny = cur.blue.first;
            int blue_nx = cur.blue.second;

            move(red_ny, red_nx, i);
            move(blue_ny, blue_nx, i);

            if (blue_ny == hole.first && blue_nx == hole.second)
                continue;

            if (red_ny == blue_ny && red_nx == blue_nx){
                switch (i) {
                    case 0:
                        cur.red.first < cur.blue.first ? red_ny-- : blue_ny--;
                        break;
                    case 1:
                        cur.red.second < cur.blue.second ? red_nx-- : blue_nx--;
                        break;
                    case 2:
                        cur.red.first < cur.blue.first ? blue_ny++ : red_ny++;
                        break;
                    case 3:
                        cur.red.second < cur.blue.second ? blue_nx++ : red_nx++;
                        break;
                }
            }

            if (visited[red_ny][red_nx][blue_ny][blue_nx])
                continue;

            state next = {cur.depth +1, {red_ny, red_nx}, {blue_ny, blue_nx}};
            q.push(next);
            visited[red_ny][red_nx][blue_ny][blue_nx] = true;
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

    cin >> N >> M;

    state start;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[i][j] = str[j];

            if (board[i][j] == 'R') {
                start.red.first = i;
                start.red.second = j;
            } else if (board[i][j] == 'B') {
                start.blue.first = i;
                start.blue.second = j;
            } else if (board[i][j] == 'O') {
                hole.first = i;
                hole.second = j;
            }
        }
    }

    start.depth = 0;
    bfs(start);
    cout << ans ;
}