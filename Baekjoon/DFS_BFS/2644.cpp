#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<int> node[501];
int visited[501];

void bfs(int start)
{
    queue<int> bfs;
    bfs.push(start);
    visited[start] = 0;

    int cur;

    while (!bfs.empty())
    {
        cur = bfs.front();
        bfs.pop();

        for (int x : node[cur])
        {
            if (visited[x] != -1)
                continue;

            visited[x] = visited[cur] + 1;
            bfs.push(x);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    memset(visited, -1, sizeof(visited));

    int n;
    cin >> n;

    int p1, p2;
    cin >> p1 >> p2;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int source;
        cin >> source;
        int destination;
        cin >> destination;

        node[source].push_back(destination);
        node[destination].push_back(source);
    }

    bfs(p1);

    cout << visited[p2];
}