//
// Created by lcy96 on 2020-09-28.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int board[9][9];

bool row[9][10] = {};
bool col[9][10] = {};
bool square[3][3][10] = {};

vector<pii> locations;
vector<int> answer;

bool check(int y, int x, int i) {
    return !(row[y][i] | col[x][i] | square[y / 3][x / 3][i]);
}

void place(int y, int x, int i) {
    row[y][i] = col[x][i] = square[y / 3][x / 3][i] = true;
}

void unPlace(int y, int x, int i) {
    row[y][i] = col[x][i] = square[y / 3][x / 3][i] = false;
}

void dfs(int y, int x, int nextIndex) {

    if (nextIndex == locations.size()+1){
        for(int i = 0; i < locations.size(); ++i){
            board[locations[i].first][locations[i].second] = answer[i];
        }

        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (check(y, x, i)) {
            place(y, x, i);

            int ny = locations[nextIndex].first;
            int nx = locations[nextIndex].second;

            answer.push_back(i);
            dfs(ny, nx, nextIndex+1);
            answer.pop_back();

            unPlace(y, x, i);
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

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 0) {
                locations.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            row[i][board[i][j]] = true;
            col[i][board[j][i]] = true;

            square[i / 3][j / 3][board[i][j]] = true;
        }
    }

    dfs(locations[0].first, locations[0].second, 1);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}