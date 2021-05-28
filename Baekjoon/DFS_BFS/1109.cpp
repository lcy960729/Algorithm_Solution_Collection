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
#define PRINT(n, m, arr) for(int i = 0; i < n; ++i){ for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << '\n';} cout << '\n';


using namespace std;

int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};

int N, M;
vector<vector<char>> map;
vector<pii > islands(1, {0, 0});

void print(vector<vector<int>> &arr) {
    for (const auto &i : arr) {
        for (const auto &j : i) {
            if (j == -1) cout << '.';
            else cout << j;
            cout << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(int y, int x, vector<vector<int>> &visited) {
    queue<pii > q;
    q.push({y, x});
    visited[y][x] = islands.size();

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N + 2 || nx < 0 || nx >= M + 2)
                continue;

            if (visited[ny][nx] != -1 || map[ny][nx] == '.')
                continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[cur.first][cur.second];
        }
    }

    islands.push_back({y, x});
}


set<int> bfs2(int curIslandId, vector<vector<int>> &g, vector<vector<int>> &islandMap) {
    vector<vector<bool>> visited(N + 2, vector<bool>(M + 2, false));

    set<int> ret;

    pii start = islands[curIslandId];

    queue<pii > q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || ny >= N + 2 || nx < 0 || nx >= M + 2)
                continue;

            if (visited[ny][nx])
                continue;

            int nextIslandId = islandMap[ny][nx];
            if (nextIslandId != -1 && curIslandId != nextIslandId) {
                ret.insert(nextIslandId);
                continue;
            }

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }

    return ret;
}

vector<vector<int>> bfs3(vector<vector<int>> &islandMap) {
    vector<vector<int>> ret(islands.size(), vector<int>());

    vector<bool> visited(islands.size(), false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        set<int> nextIslands = bfs2(cur, ret, islandMap);

        for (int next : nextIslands) {
            if (visited[next]) continue;

            q.push(next);
            visited[next] = true;

            ret[cur].push_back(next);
        }
    }

    return ret;
}

int dfs(int cur, vector<vector<int>> &g, vector<bool> &visited, vector<int> &ans) {
    int ret = 0;
    for (int next : g[cur]) {
        if (visited[next]) continue;

        visited[next] = true;
        ret = max(ret, dfs(next, g, visited, ans) + 1);
    }

    ans[ret]++;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    map.assign(N + 2, vector<char>(M + 2, '.'));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i + 1][j + 1];
        }
    }

    vector<vector<int>> bfsVisited(N + 2, vector<int>(M + 2, -1));

    for (int i = 0; i < N + 2; ++i) {
        for (int j = 0; j < M + 2; ++j) {
            if (bfsVisited[i][j] != -1 || map[i][j] == '.')
                continue;

            bfs(i, j, bfsVisited);
        }
    }

    if (islands.size() == 1) {
        cout << -1 << '\n';
        return 0;
    }

    vector<vector<int>> g = bfs3(bfsVisited);

    vector<bool> dfsVisited(islands.size(), false);
    vector<int> ans(islands.size(), 0);
    for (int i = 1; i < islands.size(); ++i) {
        if (dfsVisited[i]) continue;

        dfsVisited[i] = true;
        dfs(i, g, dfsVisited, ans);
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] == 0) break;
        cout << ans[i] << ' ';
    }
    cout << '\n';
}