//
// Created by CY on 2020-10-08.
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

int N, M, K;
char board[101][101];
string d;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int memo[101][101][81];

int dfs(pii cur, int length) {
    if (length == d.length()-1) {
        return 1;
    }

    int &ret = memo[cur.first][cur.second][length];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= K; j++) {
            int nextY = cur.first + dy[i] * j;
            int nextX = cur.second + dx[i] * j;

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
                continue;

            if (board[nextY][nextX] == d[length+1]){
                ret += dfs({nextY, nextX}, length+1);
            }
        }
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

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[i][j] = str[j];

        }
    }

    cin >> d;

    memset(memo, -1, sizeof(memo));

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == d[0])
                ans += dfs({i, j}, 0);
        }
    }

    cout << ans;
}
