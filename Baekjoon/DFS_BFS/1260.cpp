#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> node[1001];
bool visited[1001];

void bfs(int start)
{
    queue<int> bfs;
    bfs.push(start);
    visited[start] = true;

    int cur; 

    while (!bfs.empty())
    {
        cur = bfs.front();
        bfs.pop();
        cout << cur << ' ';
        for (int x : node[cur])
        {
            if (visited[x])
                continue;

            visited[x] = true;
            bfs.push(x);
        }
    }
}

void dfs(int id)
{
    cout << id << ' ';
    visited[id] = true;

    for (int x : node[id])
    {
        if (visited[x])
            continue;

        dfs(x);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int m;
    cin >> m;

    int v;
    cin >> v;

    for (int i = 0; i < m; i++)
    {
        int source;
        cin >> source;

        int destination;
        cin >> destination;

        node[source].push_back(destination);
        node[destination].push_back(source);
    }

    for (int i = 0; i < n; i++){
        sort(node[i].begin(), node[i].end());
    }

    dfs(v);
    memset(visited, false, sizeof(visited));

    cout << "\n";

    bfs(v);
}