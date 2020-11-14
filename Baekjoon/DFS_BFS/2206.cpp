#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int N, M;

int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int box[1001][1001];
int visited[1001][1001][2];

void printlog()
{
    for (int k = 0; k < 2; k++){
        cout << (k == 0 ? "false" : "true")  << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                    cout.width(2);
                    cout << visited[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}


queue<tuple<int, int, bool>> q;

int bfs(tuple<int, int, bool> start)
{
    tuple<int, int, bool> cur;

    q.push(start);
    visited[get<0>(start)][get<1>(start)][0] = 1;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        int curX = get<1>(cur);
        int curY = get<0>(cur);

        for (int i = 0; i < 4; i++){
                bool isBrokenWall = get<2>(cur);

                if (curY == N && curX == M)
                    return visited[curY][curX][isBrokenWall];

                int x = curX + dx[i];
                int y = curY + dy[i];

                if ((x < 0 || x > M) || (y < 0 || y > N))
                    continue;

                int next = box[y][x];

                int nextVisited = visited[y][x][isBrokenWall];
                int nowVisited = visited[curY][curX][isBrokenWall];

                if (next == 1 && !isBrokenWall){
                    isBrokenWall = true;
                    visited[y][x][isBrokenWall] = nowVisited + 1;
                    q.push({y, x, isBrokenWall});
                }else if (next == 0 && nextVisited == 0){
                    visited[y][x][isBrokenWall] = nowVisited + 1;
                    q.push({y, x, isBrokenWall });
                }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, 0, sizeof(visited));
    memset(box, -1, sizeof(box));

    cin >> n;
    cin >> m;

    N = n-1;
    M = m-1;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < m; j++){
            box[i][j] = str.at(j)-'0';
        }
    }

    cout << bfs({0,0, false});
}