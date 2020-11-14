//
// Created by CY on 2020-10-20.
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

int N, M, x, y, K;

int map[20][20];

int dice[6] = {0, 0, 0, 0, 0, 0};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void changeDice(int dir){
    int temp = dice[0];
    switch(dir){
        case 1:
            dice[0] = dice[4];
            dice[4] = dice[2];
            dice[2] = dice[5];
            dice[5] = temp;
            break;
        case 2:
            dice[0] = dice[5];
            dice[5] = dice[2];
            dice[2] = dice[4];
            dice[4] = temp;
            break;
        case 3:
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = temp;
            break;
        case 4:
            dice[0] = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = temp;
            break;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> y >> x >> K;

    memset(map, -1, sizeof(map));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (K--) {
        int dir;
        cin >> dir;

        int ny = dy[dir - 1] + y;
        int nx = dx[dir - 1] + x;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        changeDice(dir);

        if (map[ny][nx] == 0){
            map[ny][nx] = dice[2];
        }else{
            dice[2] = map[ny][nx];
            map[ny][nx] = 0;
        }

        x = nx;
        y = ny;

        cout << dice[0] << "\n";
    }
}