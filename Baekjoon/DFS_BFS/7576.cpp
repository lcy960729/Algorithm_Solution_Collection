#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int box[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;

int day = 0;
int tomato = 0;

void bfs()
{
    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){

            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            x = (x < 0 ? 0 : x) % 1001;
            y = (y < 0 ? 0 : y) % 1001;

            if (visited[x][y] != -1 || box[x][y] == -1)
                continue;

            visited[x][y] = visited[cur.first][cur.second] + 1;
            
            tomato--;
            day = max(day, visited[x][y]);
            
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
    memset(box, -1, sizeof(box));

    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            cin >> box[i][j];

            if (box[i][j] == 0){
                tomato++;
            }

            if (box[i][j] == 1){
                q.push({i,j});
                visited[i][j] = 0;
            }
        }
    }

    bfs();

    if (tomato == 0)
        cout << day;
    else 
        cout << -1;
}
