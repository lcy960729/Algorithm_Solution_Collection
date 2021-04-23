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

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int changeDir[] = {1, 0, 3, 2};

struct Horse {
    int y, x, dir;

    int ny() {
        return y + dy[dir];
    }

    int nx() {
        return x + dx[dir];
    }

    void reverseDir() {
        dir = changeDir[dir];
    }
};

int N, K;
int board[12][12];
Horse horses[10];

deque<int> horsesOnBoard[12][12];

bool isBlue(int y, int x) {
    return ((board[y][x] == 2) || y < 0 || y >= N || x < 0 || x >= N);
}

// BAC일때는 AC만 이동 , ABC일때는 ABC 이동
void white(int id) {
    int ny = horses[id].ny();
    int nx = horses[id].nx();

    auto &cur = horsesOnBoard[horses[id].y][horses[id].x];
    auto &next = horsesOnBoard[ny][nx];

    int size = cur.size();
    bool check = false;
    for (int i = 0; i < size; ++i) {
        if (cur.front() == id) {
            check = true;
        }

        if (check) {
            next.push_back(cur.front());

            horses[next.back()].y = ny;
            horses[next.back()].x = nx;
        } else {
            cur.push_back(cur.front());
        }

        cur.pop_front();
    }
}

void red(int id) {
    int ny = horses[id].ny();
    int nx = horses[id].nx();

    auto &cur = horsesOnBoard[horses[id].y][horses[id].x];
    auto &next = horsesOnBoard[ny][nx];

    int size = cur.size();
    for (int i = 0; i < size; ++i) {
        next.push_back(cur.back());
        horses[next.back()].y = ny;
        horses[next.back()].x = nx;

        cur.pop_back();

        if (next.back() == id) {
            return;
        }
    }
}

void blue(int id) {
    horses[id].reverseDir();

    if (isBlue(horses[id].ny(), horses[id].nx())) {
        return;
    } else if (board[horses[id].ny()][horses[id].nx()] == 0) {
        white(id);
    } else {
        red(id);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        cin >> horses[i].y >> horses[i].x >> horses[i].dir;
        horses[i].y--;
        horses[i].x--;
        horses[i].dir--;

        horsesOnBoard[horses[i].y][horses[i].x].push_back(i);
    }

    int ans = -1;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 0; j < K; ++j) {

            if (isBlue(horses[j].ny(), horses[j].nx())) {
                blue(j);
            } else if (board[horses[j].ny()][horses[j].nx()] == 0) {
                white(j);
            } else {
                red(j);
            }

            if (horsesOnBoard[horses[j].y][horses[j].x].size() >= 4) {
                ans = i;
                break;
            }
        }
        if (ans != -1) break;
    }

    cout << ans << '\n';
}