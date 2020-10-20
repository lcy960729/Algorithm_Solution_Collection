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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int cost[1001] = {};
        int result[1001] = {};

        int indegree[1001] = {};
        vector<int> adj[1001];

        queue<int> q;

        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++){
            cin >> cost[i];
        }

        while(k--){
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            indegree[y]++;
        }

        for (int i = 1; i <= n; i++){
            if (indegree[i] == 0) {
                q.push(i);
                result[i] = cost[i];
            }
        }

        int w;
        cin >> w;

        for (int i = 1; i <= n; i++){
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]){
                result[next] = max(result[next], result[cur] + cost[next]);

                if (--indegree[next] == 0)
                    q.push(next);
            }
        }
        cout << result[w] << "\n";
    }
}