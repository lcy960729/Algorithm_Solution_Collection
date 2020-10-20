//
// Created by CY on 2020-09-18.
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int result[32001];

    vector<int> adj[32001];
    queue<int> q;

    int indegree[32001] = {};

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    for (int i = 1; i <= n; i++) {
        int cur = q.front();
        q.pop();

        result[i] = cur;

        for (int next : adj[cur]) {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << result[i] << "\n";
    }
}