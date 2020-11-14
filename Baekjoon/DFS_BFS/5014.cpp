//
// Created by lcy96 on 2020-10-01.
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

int F, S, G, U, D;

vector<int> g[1000001];
int visited[1000001];

int bfs(){
    queue<int> q;
    memset(visited, -1, sizeof(visited));

    q.push(S);
    visited[S] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : g[cur]){
            if (visited[next] != -1)
                continue;

            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }

    return visited[G];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    for (int i = 1; i <= F; i++) {
        if (i + U <= F)
            g[i].push_back(i + U);

        if (i - D >= 0)
            g[i].push_back(i - D);
    }

    int answer = bfs();

    if (answer == -1){
        cout << "use the stairs";
    }else{
        cout << answer;
    }
}