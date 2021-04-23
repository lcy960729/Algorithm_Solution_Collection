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


void print(vector<vector<int>> &planerFigure) {
    for (auto &i : planerFigure) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<vector<vector<int>>> squares = {
        {
                {1, 0, 0, 0},
                {1, 1, 1, 1},
                {1, 0, 0, 0}
        },
        {
                {0, 1, 0, 0},
                {1, 1, 1, 1},
                {1, 0, 0, 0}
        },
        {
                {0, 0, 1, 0},
                {1, 1, 1, 1},
                {1, 0, 0, 0}
        },
        {
                {0, 0, 0, 1},
                {1, 1, 1, 1},
                {1, 0, 0, 0}
        },
        {
                {0, 1, 0, 0},
                {1, 1, 1, 1},
                {0, 1, 0, 0}
        },
        {
                {0, 0, 1, 0},
                {1, 1, 1, 1},
                {0, 1, 0, 0}
        },
        {
                {0, 0, 1, 1, 1},
                {1, 1, 1, 0, 0}
        },
        {
                {0, 0, 1, 1},
                {0, 1, 1, 0},
                {1, 1, 0, 0}
        },
        {
                {0, 0, 1, 1},
                {1, 1, 1, 0},
                {1, 0, 0, 0}
        },
        {
                {1, 1, 0, 0},
                {0, 1, 1, 1},
                {0, 1, 0, 0}
        },
        {
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 1, 1}
        },
};

bool isSame(vector<vector<int>> &square, vector<vector<int>> &planerFigure) {
    if ((square.size() != planerFigure.size()) || (square[0].size() != planerFigure[0].size())) {
        return false;
    }

    for (int i = 0; i < planerFigure.size(); ++i) {
        for (int j = 0; j < planerFigure[i].size(); ++j) {
            if (square[i][j] != planerFigure[i][j]) {
                return false;
            }
        }
    }

    return true;
}

vector<vector<int>> rotate(vector<vector<int>> &arr) {
    int r = arr.size();
    int c = arr[0].size();

    vector<vector<int>> newArr(c, vector<int>(r));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            newArr[i][j] = arr[r - j - 1][i];
        }
    }
    return newArr;
}

vector<vector<int>> reverse(vector<vector<int>> &arr) {
    vector<vector<int>> newArr(arr);

    for (auto &i : newArr) {
        reverse(i.begin(), i.end());
    }

    return newArr;
}

bool isYes(vector<vector<int>> &planerFigure) {
    for (auto &square : squares) {
        vector<vector<int>> temp(planerFigure);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (isSame(square, temp)) {
                    return true;
                }
                temp = rotate(temp);
            }
            temp = rotate(temp);
            temp = reverse(temp);
        }
    }

    return false;
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 3;
    while (t--) {
        vector<vector<int>> board(6, vector<int>(6));
        int sx = 1e9, ex = -1, sy = 1e9, ey = -1;

        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cin >> board[i][j];

                if (board[i][j]) {
                    sx = min(sx, j);
                    ex = max(ex, j);

                    sy = min(sy, i);
                    ey = max(ey, i);
                }
            }
        }

        vector<vector<int>> planarFigure(ey - sy + 1, vector<int>(ex - sx + 1));
        for (int i = 0; i < planarFigure.size(); ++i) {
            for (int j = 0; j < planarFigure[i].size(); ++j) {
                planarFigure[i][j] = board[i + sy][j + sx];
            }
        }

        cout << (isYes(planarFigure) ? "yes" : "no") << '\n';
    }
}