////
//// Created by CY on 2020-10-08.
////
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

struct st {
    int height, y, x;
};

struct cmp {
    bool operator()(st st1, st st2) {
        return st1.height < st2.height;
    }
};

int M, H;
initializer_list<LNode> N;

int hole[1004][1004][4];
int height[1004][1004];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

priority_queue<st, vector<st>, cmp> pq;

void dijk() {

    while (!pq.empty()) {
        st cur = pq.top();
        pq.pop();

        if (height[cur.y][cur.x] != cur.height) continue;

        for (int i = 0; i < 4; i++) {
            if (hole[cur.y][cur.x][i] == -1)
                continue;

            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 1 || ny > N || nx < 1 || nx > M)
                continue;

            int next_height = max(height[cur.y][cur.x], min(hole[cur.y][cur.x][i], height[ny][nx]));

            if (height[ny][nx] > next_height) {
                height[ny][nx] = next_height;
                pq.push({next_height, ny, nx});
            }
        }
    }

}

void enqueue(int h, int y, int x) {
    if (height[y][x] > h) {
        height[y][x] = h;
        pq.push({h, y, x});
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> H;

    for (int i =1; i <= N + 1; i++) {
        for (int j = 1; j <= M; j++) {
            int a;
            cin >> a;

            hole[i - 1][j][2] = a;
            hole[i][j][0] = a;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M + 1; j++) {
            int a;
            cin >> a;

            hole[i][j - 1][1] = a;
            hole[i][j][3] = a;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            height[i][j] = H;
        }
    }

    for (int i = 0; i <= N + 1; i++) {
        if (hole[i][0][1] != -1)
            enqueue(hole[i][0][1], i, 1);

        if (hole[i][M + 1][3] != -1)
            enqueue(hole[i][M + 1][3], i, M);
    }

    for (int i = 0; i <= M + 1; i++) {
        if (hole[0][i][2] != -1)
            enqueue(hole[0][i][2], 1, i);

        if (hole[N + 1][i][0] != -1)
            enqueue(hole[N + 1][i][0], N, i);
    }

    dijk();

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += height[i][j];
        }
    }

    cout << ans;
}


//using namespace std;
//int dy[4] = {-1, 0, 1, 0};
//int dx[4] = {0, 1, 0, -1};
//int n, m, h, hole[1004][1004][4], height[1004][1004], ret, a;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
//void enqueue(int y, int x, int h) {
//    if (height[y][x] > h) {
//        height[y][x] = h;
//        pq.push({h, 1004 * y + x});
//    }
//    return;
//}
////
//int main() {
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cin >> n >> m >> h;
//    for (int i = 1; i <= n + 1; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> a;
//            hole[i - 1][j][2] = a;
//            hole[i][j][0] = a;
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m + 1; j++) {
//            cin >> a;
//            hole[i][j - 1][1] = a;
//            hole[i][j][3] = a;
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            height[i][j] = h;
//        }
//    }
//    // 가장자리에 있는 hole을 통해 최소값을 잡는다.
//    for (int i = 0; i <= n + 1; i++) {
//        //가장 왼쪽, 오른쪽 확인
//        if (hole[i][0][1] != -1) enqueue(i, 1, hole[i][0][1]);
//        if (hole[i][m + 1][3] != -1) enqueue(i, m, hole[i][m + 1][3]);
//    }
//
//    for (int i = 0; i <= m + 1; i++) {
//        //가장 위쪽, 아래쪽 확인
//        if (hole[0][i][2] != -1) enqueue(1, i, hole[0][i][2]);
//        if (hole[n + 1][i][0] != -1) enqueue(n, i, hole[n + 1][i][0]);
//    }
//
//    while (pq.size()) {
//        int y = pq.top().second / 1004;
//        int x = pq.top().second % 1004;
//        int here_height = pq.top().first;
//        pq.pop();
//        if (height[y][x] != here_height) continue;
//        for (int i = 0; i < 4; i++) {
//            if (hole[y][x][i] == -1) continue;
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//            if (ny < 1 || ny > n || nx < 1 || nx > m) continue;
//            int next_height = max(height[y][x], min(hole[y][x][i], height[ny][nx]));
//            if (height[ny][nx] > next_height) {
//                height[ny][nx] = next_height;
//                pq.push({next_height, 1004 * ny + nx});
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            ret += height[i][j];
//        }
//    }
//    cout << ret << '\n';
//
//    return 0;
//}