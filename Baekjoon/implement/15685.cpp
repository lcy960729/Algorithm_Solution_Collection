#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

bool isSquare(int y, int x, vector<vector<bool>> &board) {
    return board[y][x] && board[y + 1][x] && board[y + 1][x + 1] && board[y][x + 1];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<bool>> board(110, vector<bool>(110, false));
    for (int i = 0; i < N; ++i) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        board[y][x] = true;

        y += dy[d];
        x += dx[d];
        board[y][x] = true;

        vector<int> dir;
        dir.push_back(d);

        for (int j = 0; j < g; ++j) {
            int size = dir.size();
            for (int k = size - 1; k >= 0; --k) {
                d = (dir[k] + 1) % 4;

                y += dy[d];
                x += dx[d];

                board[y][x] = true;

                dir.push_back(d);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            ans += isSquare(i, j, board) ? 1 : 0;
        }
    }

    cout << ans << '\n';
}