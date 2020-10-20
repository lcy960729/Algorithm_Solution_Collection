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

vector<pii> node[101];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int result[101][101] = {};
    int indegree[101] = {};

    vector<pii> adj[101];

    queue<int> q;

    int n, m;
    cin >> n >> m;

    while(m--){
        int x, y, k;
        cin >> x >> y >> k;

        adj[y].push_back({x, k});
        indegree[x]++;
    }

    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0) {
            q.push(i);
            result[i][i]=1;
        }
    }

    for (int i = 1; i <=n; i++){
        int cur = q.front();
        q.pop();

        for (pii next : adj[cur]){
            for (int j = 1; j <= n; j++)
                result[next.first][j] += result[cur][j] * next.second;

            if (--indegree[next.first] == 0)
                q.push(next.first);
        }
    }

    for (int i = 1; i <= n; i++){
        if (result[n][i])
            cout << i << " " << result[n][i] << "\n";
    }
}
