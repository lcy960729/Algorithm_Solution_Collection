#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int box[101][101];
int visited[101][101];

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = 1;

    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){

            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            x = (x < 0 ? 0 : x) % 101;
            y = (y < 0 ? 0 : y) % 101;

            if (visited[x][y] != -1 || box[x][y] == 0)
                continue;

            visited[x][y] = visited[cur.first][cur.second] + 1;
            
            if (x == n-1 && y == m-1)
                return ;

            q.push({x,y});
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    memset(box, 0, sizeof(box));

    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < m; j++){
            box[i][j] = str.at(j) - '0';
        }
    }

    bfs({0,0});

    cout << visited[n-1][m-1];
}
