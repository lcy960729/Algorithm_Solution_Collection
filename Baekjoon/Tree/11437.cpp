//
// Created by LeeChanYoung on 2021/01/04.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[50001][50001];
int depth[50001];
vector<int> g[50001];

void dp(int cur, int p){
    parent[cur][0] = p;
    depth[cur] = depth[p] + 1;
    for (int next : g[cur]) {
        if (next != p)
            dp(next, cur);
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        int diff = abs(depth[a] - depth[b]);
        for (int j = 19; j >= 0; --j) {
            if (diff & (1 << j)) {
                a = parent[j][a];
            }
        }

        if (a != b) {
            for (int j = 19; j >= 0; --j) {

            }
        }
    }


}