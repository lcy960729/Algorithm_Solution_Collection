//
// Created by LeeChanYoung on 2020/12/13.
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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            int u, v;
            cin >> u >> v;

            u--, v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> visited(n, 1);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (g[i].size() == 1)
                q.push(i);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

        }
    }
}