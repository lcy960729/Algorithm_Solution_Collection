#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

vector<pii > space;
vector<pii > picture;

void bfs(int y, int x, int H, int W, vector<vector<int>> &board, vector<vector<int>> &visited) {
    queue<pii > q;
    q.push({y, x});

    int mode = board[y][x];

    if (mode == 0) {
        space.push_back({y, x});
        visited[y][x] = space.size();
    } else {
        picture.push_back({y, x});
        visited[y][x] = 0;
    }

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                continue;

            if (visited[ny][nx] != -1 || mode != board[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second];
        }
    }
}

int bfs2(int pId, int H, int W, vector<vector<int>> &board, vector<vector<bool>> &visited,
         vector<vector<int>> &spaceRegion) {

    queue<pii > q;
    q.push(picture[pId]);

    visited[picture[pId].first][picture[pId].second] = true;

    set<int> cnt;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= H || nx < 0 || nx >= W)
                continue;

            if (visited[ny][nx]) continue;

            if (board[ny][nx] == 0) {
                cnt.insert(spaceRegion[ny][nx]);
                continue;
            }

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

    return cnt.size();
}

int hexToDec(char c) {
    if ('a' <= c && c <= 'f') {
        return 10 + c - 'a';
    } else {
        return c - '0';
    }
}

char pictureToChar[8] = {0, 'W', 'A', 'K', 'J', 'S', 'D'};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 0;
    while (true) {
        space.clear();
        picture.clear();

        t++;

        int H, W;
        cin >> H >> W;

        if (H == 0 && W == 0) break;

        vector<vector<int>> board(H + 2, vector<int>(W * 4 + 2, 0));

        for (int i = 0; i < H; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < W; ++j) {
                int num = hexToDec(s[j]);

                for (int k = 0; k < 4; ++k) {
                    if (num & (1 << (3 - k))) {
                        board[i + 1][j * 4 + k + 1] = 1;
                    }
                }
            }
        }

        W = W * 4 + 2;
        H += 2;

        vector<vector<int>> spaceRegion(H, vector<int>(W, -1));

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (spaceRegion[i][j] != -1) continue;

                bfs(i, j, H, W, board, spaceRegion);
            }
        }

        vector<char> ans;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int i = 0; i < picture.size(); ++i) {
            int cnt = bfs2(i, H, W, board, visited, spaceRegion);
            ans.push_back(pictureToChar[cnt]);
        }

        sort(ans.begin(), ans.end());

        cout << "Case " << t << ": ";
        for (auto c : ans) cout << c;
        cout << '\n';
    }
}