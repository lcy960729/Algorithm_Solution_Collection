#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<int> node[1001];
bool visited[1001];

int cnt = -1;

void dfs(int id){
    visited[id] = true;

    for (int x : node[id]){
        if (visited[x]) 
            continue;

        dfs(x);
    }
}

void bfs(int start){
    queue<int> bfs;
    bfs.push(start);
    visited[start] = true;

    int cur;

    while(!bfs.empty()){
        cur = bfs.front();
        bfs.pop();

        for (int x: node[cur]){
            if (visited[x])
                continue;

            visited[x] = true;
            bfs.push(x);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int source;
        cin >> source;
        int destination;
        cin >> destination;

        node[source].push_back(destination);
        node[destination].push_back(source);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (visited[i])
            continue;
        
        dfs(i);
        cnt++;
    }
    cout << cnt;
}