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

int n;
bool adj[501][501] = {};
vector<int> answer;
int ranking[501];

bool visited[501] = {};
bool finished[501] = {};

bool isImpossible = false;

void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = true;

    for (int i = 1; i <= n; i++){
        if (!adj[cur][i])
            continue;

        if (visited[i]){
            if (!finished[i]){
                isImpossible = true;
                return;
            }
            continue;
        }

        dfs(i);

        if (isImpossible)
            return;
    }

    finished[cur] = true;
    answer.push_back(cur);
}

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
        answer.clear();
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        memset(adj, false, sizeof(adj));
        isImpossible = false;

        cin >> n;

        for (int i = 1; i <= n; i++){
            cin >> ranking[i];
        }

        for (int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                adj[ranking[i]][ranking[j]] = true;
            }
        }

        int m;
        cin >> m;

        while(m--){
            int a, b;
            cin >> a >> b;
            adj[a][b] = !adj[a][b];
            adj[b][a] = !adj[b][a];
        }

        for(int i = 1; i <= n; i++){
            dfs(i);
        }

        if (isImpossible){
            cout << "IMPOSSIBLE\n";
        }else{
            reverse(answer.begin(), answer.end());

            for (int x : answer){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}
