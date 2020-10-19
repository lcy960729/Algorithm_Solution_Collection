//
// Created by CY on 2020-09-10.
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

int dy[] = {-1, 0, 1};

int N, M;

char map[10001][501];
bool visited[10001][501] = {};
bool check = false;

void dfs(int nowX, int nowY){
    visited[nowY][nowX] = true;

    if (nowX == M-1){
        check = true;
        map[nowY][nowX] = 'x';
        return;
    }

    for (int i = 0; i < 3; i++){
        int nextX = nowX + 1;
        int nextY = nowY + dy[i];

        if (visited[nextY][nextX] || map[nextY][nextX] == 'x' || nextY >= N || nextY < 0)
            continue;

        dfs(nextX, nextY);

        if (check){
            map[nextY][nextX] = 'x';
            break;
        }
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

    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        for (int j = 0; j < M; j++){
            map[i][j] = s[j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        check = false;

        dfs(0, i);
        //print();

        if (check)
            ans++;
    }
    cout << ans;
}