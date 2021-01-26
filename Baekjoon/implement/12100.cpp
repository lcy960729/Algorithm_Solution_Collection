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

void rotate(vector<vector<int>> &board) {
    vector<vector<int>> temp(board);
    int size = temp.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            board[i][j] = temp[size - j - 1][i];
        }
    }
}

void move(vector<vector<int>> &board) {
    vector<vector<int>> temp(board);
    int size = temp.size();

    for (int i = 0; i < size; ++i) {
        int index = 0;
        int pre = 0;
        for (int j = 0; j < size; ++j) {
            if (temp[j][i] == 0)
                continue;

            int cur = temp[j][i];
            board[j][i] = 0;

            if (cur != pre) {
                board[index++][i] = cur;
                pre = cur;
            }else{
                board[index-1][i] = cur * 2;
                pre = 0;
            }
        }
    }
}

int solve(int cnt, vector<vector<int>> board) {
    if (cnt == 5) {
        int mx = 0;
        for (int i = 0; i < board.size(); ++i) {
            mx = max(mx, *max_element(board[i].begin(), board[i].end()));
        }

        return mx;
    }

    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> temp(board);
        for (int j = 0; j < i; ++j)
            rotate(temp);

        move(temp);

        if (i != 0)
            for (int j = 0; j < 4 - i; ++j)
                rotate(temp);

        ret = max(ret, solve(cnt + 1, temp));
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

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (auto &i : board) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    cout << solve(0, board);
}