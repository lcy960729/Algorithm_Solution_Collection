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

int R, C, N;

int dy[] = {0, 0, 1, 0, -1};
int dx[] = {0, 1, 0, -1, 0};

void boom(vector<pii > &bomb, vector<vector<char>> &board, vector<vector<int>> &timer) {
    for (auto &cur : bomb) {
        int y = cur.first;
        int x = cur.second;

        for (int i = 0; i < 5; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            board[ny][nx] = '.';
            timer[ny][nx] = 0;
        }
    }
}

void print(vector<vector<char>> &board) {
    for (auto &i : board) {
        for (auto &j : i) {
            cout << j;
        }
        cout << '\n';
    }
    cout << '\n';
}

void printTimer(vector<vector<int>> &timer) {
    for (auto &i : timer) {
        for (auto &j : i) {
            cout << j;
        }
        cout << '\n';
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C >> N;

    vector<vector<int>> timer(R, vector<int>(C, 0));
    vector<vector<char>> board(R, vector<char>(C, ' '));
    for (int i = 0; i < R; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); ++j) {
            board[i][j] = s[j];
            if (board[i][j] == 'O')
                timer[i][j]++;
        }
    }
    --N;

    while (N) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }

                timer[i][j]++;
            }
        }
        if (--N == 0) break;

        vector<pii > bomb;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (++timer[i][j] >= 3) {
                    bomb.push_back({i, j});
                }
            }
        }

        boom(bomb, board, timer);
        if (--N == 0) break;
    }

    print(board);
}