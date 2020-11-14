//
// Created by lcy96 on 2020-10-01.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int t;
int n;

int g[100001];
int visited[100001] = {};
bool done[100001] = {};
int ans = 0;

void dfs(int cur) {
    if (done[cur] || visited[cur] == -1) {
        return;
    }

    if (visited[cur] == 0) {
        visited[cur] = 1;
    } else if (visited[cur] == 1) {
        done[cur] = true;
        ans++;
    }

    int next = g[cur];
    dfs(next);

    visited[cur] = -1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int s;
            cin >> s;

            g[i] = s;
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0)
                dfs(i);
        }

        cout << n - ans << "\n";

        memset(visited, 0, sizeof(visited));
        memset(done, false, sizeof(done));
        ans = 0;
    }
}