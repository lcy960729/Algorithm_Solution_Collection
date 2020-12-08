//
// Created by LeeChanYoung on 2020/11/21.
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

int t;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> g(n, vector<int>(0));

        int arr[100001];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((arr[i] & arr[j]) != 0) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        int ans = 1e9;

        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, 1e9);
            vector<int> parent(n, -1);

            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while(!q.empty()){
                int now = q.front();
                q.pop();

                for (int next : g[now]){
                    if (dist[next] == 1e9){
                        dist[next] = 1 + dist[now];
                        parent[next] = now;
                        q.push(next);
                    }else if (parent[now] != next && parent[next] != now){
                        ans = min(ans, dist[now] + dist[next] + 1);
                    }
                }
            }
        }

        if (ans == 1e9)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
}