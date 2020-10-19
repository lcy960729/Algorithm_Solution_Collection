//
// Created by CY on 2020-10-14.
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

int V;
vector<pii> g[100001];
bool visited[100001] = {};

int maxLength = 0;
int endPoint = 0;

void dfs(int now, int length) {

    if (maxLength < length){
        maxLength = length;
        endPoint = now;
    }

    for (pii next : g[now]){
        if (visited[next.first])
            continue;

        visited[next.first] = true;
        dfs(next.first, length+next.second);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V;

    for (int i = 0; i < V; i++){
        int u;
        cin >> u;

        while(true){
            int v;
            cin >> v;

            if (v == -1)
                break;

            int w;
            cin >> w;

            g[u].push_back({v, w});
        }
    }

    visited[1] = true;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));

    maxLength = 0;

    visited[endPoint] = true;
    dfs(endPoint, 0);

    cout << maxLength << "\n";
}