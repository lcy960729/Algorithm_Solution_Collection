//
// Created by lcy96 on 2020-09-30.
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

int N, K, ans;
vector<int> g[100002];

void bfs(int s) {
    queue<int> q;
    int visited[100002];
    memset(visited, -1, sizeof(visited));

    q.push(s);
    visited[s] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : g[cur]) {
            if (visited[next] != -1)
                continue;

            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    ans = visited[K];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    int loopSize = max(N, K) + 1;
    for (int i = 0; i <= loopSize; i++) {
        if (i <= K)
            g[i].push_back(i + 1);

        if (i > 0) {
            g[i].push_back(i - 1);

            if (i <= loopSize / 2) {
                g[i].push_back(2 * i);
            }
        }
    }

    bfs(N);
    cout << ans << "\n";
}