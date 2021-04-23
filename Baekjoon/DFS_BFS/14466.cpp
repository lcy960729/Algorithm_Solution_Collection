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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int N, K, R;

int getId(int y, int x) {
    return y * N + x;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> R;

    vector<pii > cows(K);
    vector<vector<bool>> roads(N * N, vector<bool>(N * N, false));

    for (int i = 0; i < R; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        roads[getId(y1, x1)][getId(y2, x2)] = true;
        roads[getId(y2, x2)][getId(y1, x1)] = true;
    }

    for (auto &cow : cows) {
        cin >> cow.second >> cow.first;
        cow.first--;
        cow.second--;
    }

    set<pii > ans;

    for (int i = 0; i < K; ++i) {
        queue<pii > q;
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        q.push(cows[i]);
        visited[cows[i].first][cows[i].second] = true;

        while (!q.empty()) {
            pii cur = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int ny = cur.first + dy[i];
                int nx = cur.second + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

                if (visited[ny][nx] || roads[getId(cur.first, cur.second)][getId(ny, nx)]) continue;

                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }

        for (int j = i + 1; j < K; ++j) {
            if (!visited[cows[j].first][cows[j].second]) {
                int cow1 = getId(cows[i].first, cows[i].second);
                int cow2 = getId(cows[j].first, cows[j].second);

                ans.insert({cow1, cow2});
                ans.insert({cow2, cow1});
            }
        }
    }

    cout << ans.size() / 2 << '\n';
}