//
// Created by CY on 2020-10-15.
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

int n, m;
int cost[100002];
vector<int> g[100002];

void dfs(int cur) {
    for (int next : g[cur]) {
        cost[next] += cost[cur];
        dfs(next);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if (a != -1)
            g[a].push_back(i);
    }

    while (m--) {
        int i, w;
        cin >> i >> w;

        cost[i] += w;
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << cost[i] << " ";
    }
}
