//
// Created by CY on 2020-09-25.
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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int answer = 0;

int N, K, row, col, L;

int board[101][101];
queue<pair<int, char>> q;
deque<pii > dq;

void print(){
    cout << answer << " second\n";
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> row >> col;
        board[row][col] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; ++i) {
        int X; char C;
        cin >> X >> C;

        q.push({X, C});
    }


    dq.push_back({1,1});
    int dir = 0;

    while (true) {
        int headY = dq.back().first + dy[dir];
        int headX = dq.back().second + dx[dir];

        answer++;

        if (headX < 1 || headX > N || headY < 1 || headY > N || board[headY][headX] == 2) {
            break;
        }

        bool isApple = (board[headY][headX] == 1);

        board[headY][headX] = 2;
        dq.push_back({headY, headX});

        if (!isApple) {
            int tailY = dq.front().first, tailX = dq.front().second;
            board[tailY][tailX] = 0;
            dq.pop_front();
        }

        if (!q.empty()) {
            int time = q.front().first;

            if (time == answer) {
                char nextDir = q.front().second;
                dir += (nextDir == 'D' ? 1 : -1);

                if (dir < 0)
                    dir += 4;

                dir %= 4;
                q.pop();
            }
        }
    }

    cout << answer << "\n";
}