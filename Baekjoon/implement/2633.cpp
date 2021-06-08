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

int sy, sx;
int ey, ex;
int N;

struct LNode {
    pii p[4];
    int mxX = 0, mxY = 0, mnX = 1e9, mnY = 1e9;

    int getDir() {
        // first = y , second = x
        if (p[1].second == p[0].second) {
            if (p[1].first < p[0].first) {
                return 0;
            } else {
                return 2;
            }
        } else if (p[1].first == p[0].first) {
            if (p[1].second > p[0].second) {
                return 1;
            } else {
                return 3;
            }
        }
    }
};

struct Node {
    int y, x, dir;
};

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sx >> sy >> ex >> ey >> N;

    vector<LNode> lNodes;

    int mxX = max(sx, ex);
    int mnX = min(sx, ex);

    int mxY = max(sy, ey);
    int mnY = min(sy, ey);

    for (int i = 0; i < N; ++i) {
        LNode lNode;

        for (int j = 0; j < 4; ++j) {
            cin >> lNode.p[j].second >> lNode.p[j].first;

            lNode.mxY = max(lNode.mxY, lNode.p[j].first);
            lNode.mnY = min(lNode.mnY, lNode.p[j].first);

            lNode.mxX = max(lNode.mxX, lNode.p[j].second);
            lNode.mnX = min(lNode.mnX, lNode.p[j].second);
        }

        lNodes.push_back(lNode);

        mxX = max(lNode.mxX, mxX);
        mnX = min(lNode.mnX, mnX);

        mxY = max(lNode.mxY, mxY);
        mnY = min(lNode.mnY, mnY);
    }

    vector<vector<vector<bool>>> check(4, vector<vector<bool>>(mxY + 2, vector<bool>(mxX + 2, true)));

    for (auto &lNode : lNodes) {
        int dir = lNode.getDir();

        for (int i = lNode.mnY; i <= lNode.mxY; ++i) {
            for (int j = lNode.mnX; j <= lNode.mxX; ++j) {
                // 오른쪽, 아래쪽, 왼쪽, 위쪽
                if (dir == 0 && (lNode.p[3].second <= j && lNode.p[3].first <= i)) {
                    if (lNode.p[3].second == j && i < lNode.mxY) {
                        check[2][i][j] = false;
                    }
                    if (lNode.p[3].first == i && j < lNode.mxX) {
                        check[3][i][j] = false;
                    }
                } else if (dir == 1 && (lNode.p[3].second >= j && lNode.p[3].first <= i)) {
                    if (lNode.p[3].second == j && i < lNode.mxY) {
                        check[0][i][j] = false;
                    }
                    if (lNode.p[3].first == i && j > lNode.mnX) {
                        check[3][i][j] = false;
                    }
                } else if (dir == 2 && (lNode.p[3].second >= j && lNode.p[3].first >= i)) {
                    if (lNode.p[3].second == j && i > lNode.mnY) {
                        check[0][i][j] = false;
                    }
                    if (lNode.p[3].first == i && j > lNode.mnX) {
                        check[1][i][j] = false;
                    }
                } else if (dir == 3 && (lNode.p[3].second <= j && lNode.p[3].first >= i)) {
                    if (lNode.p[3].second == j && i > lNode.mnY) {
                        check[2][i][j] = false;
                    }
                    if (lNode.p[3].first == i && j < lNode.mxX) {
                        check[1][i][j] = false;
                    }
                } else {
                    // 오른쪽, 아래쪽, 왼쪽, 위쪽
                    if (i == lNode.mnY && (lNode.mnX < j && j < lNode.mxX)) {
                        check[1][i][j] = false;
                    }
                    if (i == lNode.mxY && (lNode.mnX < j && j < lNode.mxX)) {
                        check[3][i][j] = false;
                    }
                    if (j == lNode.mnX && (lNode.mnY < i && i < lNode.mxY)) {
                        check[0][i][j] = false;
                    }
                    if (j == lNode.mxX && (lNode.mnY < i && i < lNode.mxY)) {
                        check[2][i][j] = false;
                    }
                }
            }
        }
    }
//
//    // 오른쪽, 아래쪽, 왼쪽, 위쪽
//    for (int k = 0; k < 4; ++k) {
//        for (int i = 0; i < mxY + 2; ++i) {
//            for (int j = 0; j < mxX + 2; ++j) {
//                cout << (check[k][i][j] ? 1 : 0) << ' ';
//            }
//            cout << '\n';
//        }
//        cout << '\n';
//    }

    vector<vector<vector<int>>> visited(4, vector<vector<int>>(mxY + 2, vector<int>(mxX + 2, -1)));

    queue<Node> q;
    for (int i = 0; i < 4; ++i) {
        q.push({sy, sx, i});
        visited[i][sy][sx] = 0;
    }

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int dist = visited[cur.dir][cur.y][cur.x] + (cur.dir == i ? 0 : 1);

            if (ny < 0 || ny >= mxY + 2 || nx < 0 || nx >= mxX + 2)
                continue;

            if (visited[i][ny][nx] != -1 && visited[i][ny][nx] <= dist) continue;

            if (!check[i][cur.y][cur.x]) continue;

            q.push({ny, nx, i});
            visited[i][ny][nx] = dist;
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 4; ++i) {
        if (visited[i][ey][ex] != -1)
            ans = min(ans, visited[i][ey][ex]);
    }

    cout << ans << '\n';
}