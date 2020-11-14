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

const int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

int n = 5;
char board[5][5];

bool inRange(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n)
        return false;
    else
        return true;
}

bool hasWord(int y, int x, const string &word) {
    if (!inRange(y, x))
        return false;

    if (board[y][x] != word[0])
        return false;

    if (word.size() == 1)
        return true;

    for (int i = 0; i < 8; ++i){
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
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

    int t;
    cin >> t;

    while(t--){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }
        int m;
        cin >> m;

        while(m--){
            string s;
            cin >> s;

            bool isFind = false;
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    isFind |= hasWord(i, j, s);
                }
            }
            cout << s << " " << (isFind ? "YES\n" : "NO\n");
        }
    }
}
