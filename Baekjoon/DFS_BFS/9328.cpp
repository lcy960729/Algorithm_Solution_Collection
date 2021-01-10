//
// Created by LeeChanYoung on 2020/12/31.
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


int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(int h, int w, vector<vector<char>> &board, vector<bool> &keys) {
    bool visited[103][103] = {};
    vector<vector<pii > > doors(27, vector<pii >());

    queue<pii > q;
    q.push({0, 0});
    visited[0][0] = true;

    int ans = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];

            if (nextY < 0 || nextY > h || nextX < 0 || nextX > w)
                continue;

            char item = board[nextY][nextX];

            if (visited[nextY][nextX] || item == '*')
                continue;

            if ('A' <= item && item <= 'Z') {
                doors[item - 'A'].push_back({nextY, nextX});

                if (keys[item - 'A']) {
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            } else if ('a' <= item && item <= 'z') {
                keys[item - 'a'] = true;

                for (pii door : doors[item - 'a']) {
                    if (visited[door.first][door.second])
                        continue;

                    q.push(door);
                    visited[door.first][door.second] = true;
                }

                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            } else {
                if (item == '$')
                    ans++;

                q.push({nextY, nextX});
                visited[nextY][nextX] = true;
            }
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;

        vector<vector<char>> board(h + 2, vector<char>(w + 2, '.'));
        for (int i = 1; i <= h; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= w; j++) {
                board[i][j] = s[j - 1];
            }
        }
        string key;
        cin >> key;

        vector<bool> keys(27, false);
        if (key != "0") {
            for (char c : key) {
                keys[c - 'a'] = true;
            }
        }

        cout << bfs(h + 1, w + 1, board, keys) << "\n";
    }
}
