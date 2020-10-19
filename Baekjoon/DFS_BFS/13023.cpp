//
// Created by lcy96 on 2020-09-10.
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

int N, M;
vector<int> node[2001];
bool ans = false;
bool visited[2001]={};

void dfs(int start, int depth){
    visited[start] = true;

    if (depth == 4){
        ans = true;
        return;
    }

    for (int next : node[start]){
        if (visited[next])
            continue;

        dfs(next, depth+1);
    }

    visited[start] = false;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);
    }

    for (int i = 0; i < N; i++){
        dfs(i,0);
    }
    cout << ans;

}
