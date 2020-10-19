//
// Created by CY on 2020-09-11.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int t;
int h, w;
char map[105][105];

struct node {
    int x;
    int y;
};

void bfs(node start, int (*memo)[105]) {
    bool visited[105][105] = {};
    deque<node> q;

    q.push_back({start.x, start. y});
    visited[start.y][start.x] = true;

    while (!q.empty()) {
        node now = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int nextX = now.x + dx[i];
            int nextY = now.y + dy[i];

            if (nextY < 0 || nextY >= h+2 || nextX < 0 || nextX >= w+2)
                continue;

            if (visited[nextY][nextX] || map[nextY][nextX] == '*')
                continue;

            visited[nextY][nextX] = true;

            if (map[nextY][nextX] == '#') {
                memo[nextY][nextX] = memo[now.y][now.x] + 1;
                q.push_back({nextX, nextY});
            }else{
                memo[nextY][nextX] = memo[now.y][now.x];
                q.push_front({nextX, nextY});
            }
        }
    }
}

void print(int (*memo)[105]) {
    for (int i = 0; i < h+2; i++) {
        for (int j = 0; j < w+2; j++) {
                cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int k = 0; k < t; k++) {

        cin >> h >> w;

        int memo[3][105][105] = {};

        vector<node> startPoint;
        startPoint.push_back({0,0});

        for (int i = 0; i < h+2; i++) {
            for (int j = 0; j < w+2; j++) {
                if (i == 0 || i == h+1 || j == 0 || j == w+1)
                    map[i][j] = '.';
                else {
                    cin >> map[i][j];

                    if (map[i][j] == '$')
                        startPoint.push_back({j, i});
                }
            }
        }

        for (int i = 0 ; i < 3; i++){
            bfs(startPoint[i], memo[i]);
            //print(memo[i]);
        }

        int ans = 1e9;
        for (int i = 0; i < h+2; i++) {
            for (int j = 0; j < w+2; j++) {
                if (map[i][j] == '*')
                    continue;

                int sum = memo[0][i][j] + memo[1][i][j] + memo[2][i][j];
                if (map[i][j] == '#')
                    sum -= 2;

                ans = min(ans, sum);
            }
        }
        cout << ans << '\n';
    }
}