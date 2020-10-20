//
// Created by lcy96 on 2020-09-22.
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

int t, h, w;
vector<vector<int>> board(20, vector<int>(20));

const int coverType[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};

bool set(vector<vector<int>> &boardTemp, int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w){
            ok = false;
        }else if((boardTemp[ny][nx] += delta) > 1){
            ok = false;
        }
    }
    return ok;
}

int cover(vector<vector<int>> &boardTemp){
    int y = -1, x = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; i < w; ++j) {
            if (boardTemp[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
            if (y != -1) break;
        }
    }

    if (y == -1)
        return 1;

    int ret = 0;
    for (int type = 0; type < 4; ++type){
        if (set(boardTemp, y, x, type, 1))
            ret += cover(boardTemp);

        set(boardTemp, y, x, type, -1);
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

    cin >> t;

    while (t--) {
        cin >> h >> w;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;

                board[i][j] = (c == '#' ? 1 : 0);
            }
        }
        cout << cover(board) << "\n";
    }
}