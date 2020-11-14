//
// Created by CY on 2020-10-30.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

#define watch(A,B,C,D) cout << A << " | " << B << " | " << C << " | " << D << "\n"

using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int n, m;

int memo[50][50][4];
char board[50][50];

bool visited[50][50][4] = {};
bool cycle = false;

int dfs(int curY, int curX, int dir, int depth) {
    //watch(curY,curX,dir,depth);
    int &ret = memo[curY][curX][dir];

    if (ret != -1)
        return ret;

    for (int i = 0; i < 4; i++) {
        int nextY = curY + dy[i] * (board[curY][curX] - '0');
        int nextX = curX + dx[i] * (board[curY][curX] - '0');

        if (board[nextY][nextX] == 'H' || nextY < 0 || nextY > n - 1 || nextX < 0 || nextX > m - 1) {
            ret = max(ret, 0);
            continue;
        }

        if (visited[nextY][nextX][i]) {
            cycle = true;
            continue;
        }

        visited[nextY][nextX][i] = true;
        ret = max(ret, dfs(nextY, nextX, i, depth+1));
        visited[nextY][nextX][i] = false;
    }

    ret++;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j];
        }
    }

    dfs(0, 0, 0,0);

    if (cycle) {
        cout << -1;
    } else {
        cout << memo[0][0][0];
    }
}
