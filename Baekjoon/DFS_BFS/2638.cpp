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

int N, M;
vector<vector<int>> cheese;

bool check() {
    for (auto &i : cheese) {
        for (auto &j : i) {
            if (j == 1) return false;
        }
    }

    return true;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    cheese.assign(N, vector<int>(M));

    for (auto &i : cheese) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    int ans = 0;
    while (!check()) {
        ans++;

        vector<vector<int>> visited(N, vector<int>(M, 0));

        queue<pii > q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;

                if (cheese[ny][nx] == 1 && ++visited[ny][nx] >= 2) {
                    cheese[ny][nx] = 0;
                    continue;
                }

                if (visited[ny][nx] != 0) continue;

                q.push({ny, nx});
                visited[ny][nx] = -1;
            }
        }
    }

    cout << ans << '\n';
}