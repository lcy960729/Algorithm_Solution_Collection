#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<int> node[501];
bool visited[501];

int friends;

void bfs(int start)
{
    queue<pair<int, int>> bfs;
    bfs.push({start, 0});
    visited[start] = true;

    pair<int, int> cur;

    while (!bfs.empty())
    {
        cur = bfs.front();
        bfs.pop();

        if (cur.second > 2){
            continue;
        }

        friends++;
        for (int x : node[cur.first])
        {
            if (visited[x])
                continue;

            visited[x] = true;
            bfs.push({x, cur.second + 1});
        }
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

    for (int i = 0; i < m; i++)
    {
        int source;
        cin >> source;
        int destination;
        cin >> destination;

        node[source].push_back(destination);
        node[destination].push_back(source);
    }

    friends = -1;
    bfs(1);

    cout << friends;
}