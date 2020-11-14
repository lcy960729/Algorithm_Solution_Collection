//
// Created by CY on 2020-10-13.
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

int N;
vector<pii > g[10002];

bool visited[10002] = {};

int maxLength = 0;
int endpoint = 0;

void dfs(int start, int length) {

    if (maxLength < length) {
        maxLength = length;
        endpoint = start;
    }

    for (pii next : g[start]) {
        if (visited[next.first])
            continue;

        visited[next.first] = true;
        dfs(next.first, length + next.second);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    visited[1] = true;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));

    visited[endpoint] = true;

    maxLength = 0;
    dfs(endpoint, 0);
    cout << maxLength << "\n";
}