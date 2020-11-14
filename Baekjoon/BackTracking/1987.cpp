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

int N, M;
char board[21][21];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool visited[21][21] = {};

int ans = 0;
bool selected[26] = {};

void dfs(int y, int x, int cnt){

    if (cnt == N*M){
        ans = max(ans, cnt);
        return;
    }

    for (int i = 0 ; i < 4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (nx < 1 || nx > M || ny < 1 || ny > N)
            continue;

        if (visited[ny][nx])
            continue;

        if (selected[board[ny][nx]-'A']){
            ans = max(ans, cnt);
            continue;
        }

        visited[ny][nx] = true;
        selected[board[ny][nx]-'A'] = true;

        dfs(ny, nx, cnt+1);

        visited[ny][nx] = false;
        selected[board[ny][nx]-'A'] = false;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    string str;
    for (int i = 1; i <= N; ++i){
        cin >> str;
        for (int j = 0; j < M; ++j){
            board[i][j+1] = str[j];
        }
    }
    visited[1][1] = true;
    selected[board[1][1]-'A'] = true;
    dfs(1,1,1);

    cout << ans;
}