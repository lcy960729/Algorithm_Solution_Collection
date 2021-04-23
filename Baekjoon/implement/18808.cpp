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


bool canStick(int y, int x, vector<vector<int>> &board, vector<vector<int>> &sticker) {
    for (int i = 0; i < sticker.size(); ++i) {
        for (int j = 0; j < sticker[i].size(); ++j) {
            if (board[i + y][j + x] + sticker[i][j] == 2) {
                return false;
            }
        }
    }

    return true;
}

void stick(int y, int x, vector<vector<int>> &board, vector<vector<int>> &sticker) {
    for (int i = 0; i < sticker.size(); ++i) {
        for (int j = 0; j < sticker[i].size(); ++j) {
            board[i + y][j + x] += sticker[i][j];
        }
    }
}

bool isDone(vector<vector<int>> &board, vector<vector<int>> &sticker) {
    int N = board.size();
    int M = board[0].size();

    int r = sticker.size();
    int c = sticker[0].size();

    for (int i = 0; i < N - r + 1; i++) {
        for (int j = 0; j < M - c + 1; ++j) {
            if (canStick(i, j, board, sticker)) {
                stick(i, j, board, sticker);
                return true;
            }
        }
    }

    return false;
}

vector<vector<int>> rotate(vector<vector<int>> &sticker) {
    int r = sticker.size();
    int c = sticker[0].size();

    vector<vector<int>> newSticker(c, vector<int>(r));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            newSticker[i][j] = sticker[r - j - 1][i];
        }
    }
    return newSticker;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> board(N, vector<int>(M, 0));

    while (K--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C, 0));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> sticker[i][j];
            }
        }

        for (int k = 0; k < 4; ++k) {
            if (isDone(board, sticker)) {
                break;
            }
            sticker = rotate(sticker);
        }
    }

    int ans = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 1) ans++;
        }
    }
    cout << ans << '\n';
}