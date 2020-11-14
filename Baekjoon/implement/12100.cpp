//
// Created by CY on 2020-09-25.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;

void print(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate(vector<vector<int>> &board) {
    vector<vector<int>> temp(board.size());
    copy(board.begin(), board.end(), temp.begin());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = temp[N - 1 - j][i];
        }
    }
}

void reverse(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        reverse(board[i].begin(), board[i].end());
    }
}

void move(vector<vector<int>> &board) {
    stack<int> st;
    stack<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] == 0)
                continue;

            if (!st.empty() && board[i][j] == st.top()) {
                st.pop();
                result.push(board[i][j] * 2);

                while(!st.empty()){
                    result.push(st.top());
                    st.pop();
                }
            } else {
                st.push(board[i][j]);
            }
        }

        while (!st.empty()) {
            result.push(st.top());
            st.pop();
        }

        for (int j = 0; j < N; j++) {
            if (j < N - result.size()) {
                board[i][j] = 0;
            } else {
                board[i][j] = result.top();
                result.pop();
            }
        }
    }
}

int solve(vector<vector<int>> &board, int depth) {
    if (depth == 5) {
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, board[i][j]);
            }
        }
        return result;
    }

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp(board.size());
        copy(board.begin(), board.end(), temp.begin());

        if (i == 1) {
            reverse(temp);
        } else if (i == 2) {
            rotate(temp);
        } else if (i == 3) {
            reverse(temp);
            rotate(temp);
        }

        move(temp);

        if (i == 1) {
            reverse(temp);
        } else if (i == 2) {
            rotate(temp);
            rotate(temp);
            rotate(temp);
        } else if (i == 3) {
            reverse(temp);
            rotate(temp);
            rotate(temp);
            rotate(temp);
        }

        //print(temp);

        ret = max(ret, solve(temp, depth + 1));
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

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    print(board);
    rotate(board);

    move(board);

    rotate(board);
    rotate(board);
    rotate(board);

    print(board);
    //cout << solve(board, 0) << "\n";
    //오른쪽 왼쪽 다음엔 위쪽 아니면 아래
}