//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <cmath>
//#include <queue>
//
//#define pii pair<int, int>
//#define ll long long
//#define Int_MAX 1e9
//#define LL_MAX 3e18
//
//using namespace std;
//
//int dy[] = {0, 1, 0, -1};
//int dx[] = {1, 0, -1, 0};
//
//struct Node {
//    int y, x, dir;
//};
//
//int main() {
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int W, H;
//    cin >> W >> H;
//
//    vector<vector<char>> board(H, vector<char>(W));
//    vector<vector<vector<int>>> visited(H, vector<vector<int>>(W, vector<int>(5, -1)));
//
//    vector<pii > C;
//    for (int i = 0; i < H; ++i) {
//        for (int j = 0; j < W; ++j) {
//            cin >> board[i][j];
//
//            if (board[i][j] == 'C') {
//                C.push_back({i, j});
//            }
//        }
//    }
//
//    queue<Node> q;
//    q.push({C[0].first, C[0].second, 4});
//    visited[C[0].first][C[0].second][4] = 0;
//
//    int ans = 1e9;
//    while (!q.empty()) {
//        Node cur = q.front();
//        q.pop();
//
//        if (cur.y == C[1].first && cur.x == C[1].second) {
//            ans = min(ans, visited[cur.y][cur.x][cur.dir]);
//            continue;
//        }
//
//        for (int i = 0; i < 4; ++i) {
//            int j = 1;
//            while (true) {
//                int ny = cur.y + (dy[i] * j);
//                int nx = cur.x + (dx[i] * j);
//
//                if (ny < 0 || ny >= H || nx < 0 || nx >= W) break;
//
//                if (visited[ny][nx][i] != -1 || board[ny][nx] == '*') break;
//
//                q.push({ny, nx, i});
//                visited[ny][nx][i] = visited[cur.y][cur.x][cur.dir] + (cur.dir != i ? 1 : 0);
//
//                j++;
//            }
//        }
//    }
//
//    cout << ans-1 << '\n';
//}
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct Node {
    int y, x, dir;
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int W, H;
    cin >> W >> H;

    vector<vector<char>> board(H, vector<char>(W));
    vector<vector<int>> visited(H, vector<int>(W, -1));

    vector<pii > C;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'C') {
                C.push_back({i, j});
            }
        }
    }

    queue<Node> q;
    q.push({C[0].first, C[0].second, -1});
    visited[C[0].first][C[0].second] = 0;

    int ans = 1e9;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.y == C[1].first && cur.x == C[1].second) {
            ans = visited[cur.y][cur.x];
            break;
        }

        for (int i = 0; i < 4; ++i) {

            int j = 1;
            while (true) {
                int ny = cur.y + (dy[i] * j);
                int nx = cur.x + (dx[i] * j);

                if (ny < 0 || ny >= H || nx < 0 || nx >= W) break;

                if (board[ny][nx] == '*') break;

                // 쭉 나아가서 도달할 수 없을때 까지 넣는다. 중간에 이미 왔다 간곳은 추가하지 않는다.
                // 이유는 도달할 수 없을 때 까지 넣기 때문에 무조건 짧게 가는 방향이 먼저 가게 되어있다.
                if (visited[ny][nx] == -1) {
                    q.push({ny, nx, i});
                    visited[ny][nx] = visited[cur.y][cur.x] + (cur.dir != i ? 1 : 0);
                }
                j++;
            }
        }
    }

    cout << ans - 1 << '\n';
}