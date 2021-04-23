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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

bool isYes(vector<vector<char>> &board, vector<pii > &teacher) {
    for (int i = 0; i < teacher.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int ny = teacher[i].first;
            int nx = teacher[i].second;

            while (true) {
                ny += dy[j];
                nx += dx[j];

                if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())
                    break;

                if (board[ny][nx] == 'O')
                    break;
                else if (board[ny][nx] == 'S')
                    return false;
            }
        }
    }
    return true;
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

    vector<vector<char>> board(N, vector<char>(N));

    vector<pii > emptyZone;
    vector<pii > teacher;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'X') {
                emptyZone.push_back({i, j});
            } else if (board[i][j] == 'T') {
                teacher.push_back({i, j});
            }
        }
    }

    vector<bool> check(emptyZone.size(), false);
    for (int i = 0; i < 3; ++i) {
        check[emptyZone.size() - 1 - i] = true;
    }

    do {
        vector<vector<char>> temp(board);
        for (int i = 0; i < check.size(); ++i) {
            if (!check[i]) continue;

            temp[emptyZone[i].first][emptyZone[i].second] = 'O';
        }

        if (isYes(temp, teacher)) {
            cout << "YES";
            return 0;
        }

    } while (next_permutation(check.begin(), check.end()));

    cout << "NO";
}