#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<int> node[101];
bool visited[101];

int cnt = -1;

void dfs(int id){
    cnt++;

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
        cnt++;
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

    bfs(1);
    cout << cnt;
}