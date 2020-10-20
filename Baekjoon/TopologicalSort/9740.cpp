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
        int indegree[1001] = {};
        int result[1001] = {};
        int cnt[1001] = {};
        vector<int> adj[1001];

        queue<int> q;

        int k, m, p;
        cin >> k >> m >> p;

        while(p--){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            indegree[b]++;
        }

        for (int i = 1; i <= m; i++){
            if (indegree[i] == 0) {
                result[i] = 1;
                q.push(i);
            }
        }

        for (int i = 1; i <= m; i++){
            int cur = q.front();
            q.pop();

            for (int next : adj[cur]){
                if (result[next] == result[cur])
                    cnt[next]++;
                else if (result[next] < result[cur]){
                    result[next] = result[cur];
                    cnt[next] = 1;
                }

                if (--indegree[next] == 0){
                    if (cnt[next] > 1)
                        result[next]++;

                    q.push(next);
                }
            }
        }

        cout << k << " " << result[m] << "\n";
    }
}