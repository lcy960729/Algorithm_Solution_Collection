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

    vector<int> adj[1001];
    int indegree[1001] = {};

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int k;
        cin >> k;

        int pre;
        cin >> pre;
        for (int j = 1; j < k; j++){
            int cur;
            cin >> cur;

            adj[pre].push_back(cur);
            indegree[cur]++;
            pre = cur;
        }
    }

    int result[1001];
    queue<int> q;

    for (int i = 1; i <= n; i++){
        if (indegree[i] == 0)
            q.push(i);
    }

    for (int i = 1; i <= n; i++){
        if (q.empty()){
            cout << 0 << "\n";
            return 0;
        }

        int cur = q.front();
        q.pop();

        result[i] = cur;
        for (int next : adj[cur]){
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << result[i] << "\n";
    }
}