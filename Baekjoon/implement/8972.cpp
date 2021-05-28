#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dx[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int R, C;
vector<vector<char>> board;
vector<pii > crazyArduino;
pii jsArduino;

int calcDist(pii crazyArduino) {
    return abs(jsArduino.first - crazyArduino.first) + abs(jsArduino.second - crazyArduino.second);
}

bool moveJsArduino(int dir) {
    int ny = jsArduino.first + dy[dir];
    int nx = jsArduino.second + dx[dir];

    if (board[ny][nx] == 'R') {
        return false;
    }

    board[jsArduino.first][jsArduino.second] = '.';
    board[ny][nx] = 'I';

    jsArduino.first = ny;
    jsArduino.second = nx;

    return true;
}

bool moveCrazyArduino() {
    map<pii, int> cnt;

    for (int i = 0; i < crazyArduino.size(); ++i) {

        pii mn = crazyArduino[i];
        for (int j = 1; j <= 9; ++j) {
            pii next;
            next.first = crazyArduino[i].first + dy[j];
            next.second = crazyArduino[i].second + dx[j];

            if (next.first < 0 || next.first >= R || next.second < 0 || next.second >= C)
                continue;

            if (calcDist(mn) > calcDist(next)) {
                mn = next;
            }
        }

        if (board[mn.first][mn.second] == 'I') {
            return false;
        }

        board[crazyArduino[i].first][crazyArduino[i].second] = '.';
        cnt[mn]++;
    }

    crazyArduino.clear();
    for (const auto[key, value] : cnt) {
        if (value >= 2) {
            board[key.first][key.second] = '.';
        } else {
            board[key.first][key.second] = 'R';
            crazyArduino.push_back(key);
        }
    }

    return true;
}

void print() {
    for (auto &i : board) {
        for (auto &j : i) {
            cout << j;
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    // R 미친 아두이노
    // I 종수 아두이노

    board.assign(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                crazyArduino.push_back({i, j});
            } else if (board[i][j] == 'I') {
                jsArduino = {i, j};
            }
        }
    }

    string s;
    cin >> s;

    bool check = true;
    for (int i = 0; i < s.size(); ++i) { ;
        check &= moveJsArduino(s[i] - '0');
        check &= moveCrazyArduino();

//        print();

        if (!check) {
            cout << "kraj " << i + 1 << '\n';
            return 0;
        }
    }

    print();
}