//
// Created by LeeChanYoung on 2020/11/19.
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
char board[11][11];

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int memo[11][11][8] = {};

int dfs(int y, int x, int length, string &str) {
    if (str.length()-1 == length){
        return 1;
    }

    int &ret = memo[y][x][length];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 8; i++) {
        int ny = (y + dy[i]) % N;
        if (ny < 0) ny += N;

        int nx = (x + dx[i]) % M;
        if (nx < 0) nx += M;

        if (str[length + 1] == board[ny][nx]) {
            ret += dfs(ny, nx, length + 1, str);
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
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    while (K--) {
        memset(memo, -1, sizeof(memo));

        string str;
        cin >> str;

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == str[0])
                    ans += dfs(i,j,0,str);
            }
        }
        cout << ans << "\n";
    }
}