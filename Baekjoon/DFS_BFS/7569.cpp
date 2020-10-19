#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int z, y, x;
} ZXY;


int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int box[101][101][101];
int visited[101][101][101];
queue<ZXY> q;

int day = 0;
int tomato = 0;

void bfs()
{
    ZXY cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++){
                int x = cur.x + dx[i];
                int y = cur.y + dy[i];
                int z = cur.z + dh[i];

                x = (x < 0 ? 0 : x) % 101;
                y = (y < 0 ? 0 : y) % 101;
                z = (z < 0 ? 0 : z) % 101;

                if (visited[z][y][x] != -1 || box[z][y][x] == -1)
                    continue;

                visited[z][y][x] = visited[cur.z][cur.y][cur.x] + 1;
                
                tomato--;
                day = max(day, visited[z][y][x]);
                
                q.push({z,y,x});
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

    int h;
    cin >> h;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < m; j++){
                for (int k = 0; k < n; k++){
                    cin >> box[i][j][k];

                    if (box[i][j][k] == 0){
                        tomato++;
                    }

                    if (box[i][j][k] == 1){
                        q.push({i, j , k});
                        visited[i][j][k] = 0;
                    }
                }
            }
    }

    bfs();

    if (tomato == 0)
        cout << day;
    else 
        cout << -1;
}
