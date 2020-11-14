//
// Created by lcy96 on 2020-10-01.
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
vector<int> g[10001];
bool visited[10001] = {};
int hacking[10001] = {};
int ans = 0;

void dfs(int cur){
    hacking[cur]++;
    ans = max(ans, hacking[cur]);

    for (int next : g[cur]){
        if (visited[next])
            continue;

        visited[next] = true;
        dfs(next);
    }
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
        int A, B;
        cin >> A >> B;

        g[A].push_back(B);
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, false , sizeof(visited));
        visited[i] = true;
        dfs(i);
    }

    for (int i = 1; i <= N; i++) {
        if (hacking[i] == ans)
            cout << i << " ";
    }
}