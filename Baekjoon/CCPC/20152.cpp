//
// Created by LeeChanYoung on 2020/11/22.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int H, N;

int S, E , size;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int visited[31][31] = {};

int shortestDist;

void bfs(pii home) {
    memset(visited, -1, sizeof(visited));

    queue<pii > q;
    q.push(home);
    visited[home.first][home.second] = 1;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny > size || nx < 0 || nx > size || ny > nx)
                continue;

            if (visited[ny][nx] != -1) {
                continue;
            }

            visited[ny][nx] = visited[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }

    shortestDist = visited[E][E];
}

ll memo[31][31][62];
bool visited2[31][31];

ll dp(int y, int x, int dist){
    if (dist > shortestDist){
        return 0;
    }

    if (y == E && x == E && dist == shortestDist){
        return 1;
    }

    long long &ret = memo[y][x][dist];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny > size || nx < 0 || nx > size || ny > nx)
            continue;

        if (visited2[ny][nx]) {
            continue;
        }

        visited2[ny][nx] = true;
        ret += dp(ny, nx, dist+1);
        visited2[ny][nx] = false;
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

    cin >> H >> N;

    if (H > N) {
        S = H - N;
        E = 0;
    } else {
        S = 0;
        E = N - H;
    }

    size = abs(H-N);

    bfs({S, S});
    memset(memo, -1, sizeof(memo));
    cout << dp(S, S, 1);
}