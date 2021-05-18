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

int A, B, N, M;
vector<vector<int>> board;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

struct Query {
    int robotId;
    char op;
    int num;
};

struct Robot {
    int id, x, y, dir;

    void setDir(char dir) {
        if (dir == 'N') this->dir = 0;
        else if (dir == 'E') this->dir = 1;
        else if (dir == 'S') this->dir = 2;
        else if (dir == 'W') this->dir = 3;
    }

    void opL() {
        dir = ((dir - 1) + 4) % 4;
    }

    void opR() {
        dir = (dir + 1) % 4;
    }

    bool opF() {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (isCrashedIntoTheWall(ny, nx)) {
            cout << "Robot " << id << " crashes into the wall\n";
            return false;
        }

        if (isCrashedIntoRobot(ny, nx)) {
            cout << "Robot " << id << " crashes into robot " << board[ny][nx] << '\n';
            return false;
        }

        board[y][x] = -1;
        board[ny][nx] = id;
        x = nx;
        y = ny;

        return true;
    }

    bool isCrashedIntoTheWall(int ny, int nx) {
        return (nx < 0 || nx >= A || ny < 0 || ny >= B);
    }

    bool isCrashedIntoRobot(int ny, int nx) {
        return (board[ny][nx] != -1);
    };
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> A >> B >> N >> M;

    board.assign(B, vector<int>(A, -1));

    vector<Robot> robots(N);
    for (int i = 0; i < N; ++i) {
        int x, y;
        char dir;
        cin >> x >> y >> dir;

        robots[i].id = i + 1;
        robots[i].x = x - 1;
        robots[i].y = B - y;
        robots[i].setDir(dir);

        board[robots[i].y][robots[i].x] = robots[i].id;
    }

    vector<Query> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i].robotId >> queries[i].op >> queries[i].num;
        queries[i].robotId--;
    }

    for (const auto &query : queries) {
        int id = query.robotId;
        char op = query.op;
        int t = query.num;

        while (t--) {
            if (op == 'L') {
                robots[id].opL();
            } else if (op == 'R') {
                robots[id].opR();
            } else if (op == 'F') {
                if (!robots[id].opF()) return 0;
            }
        }
    }

    cout << "OK\n";
}

