#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

char box[51][51];
int visited[51][51];

deque<pair<int, int>> q;

void bfs()
{
    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++){

            int x = cur.second + dx[i];
            int y = cur.first + dy[i];

            if (x < 0 || x >= m)
                continue;

            if (y < 0 || y >= n)
                continue;

            char now = box[cur.first][cur.second];
            char next = box[y][x];

            if (visited[y][x] != -1 || next == -1 || next == 'X')
                continue;

            if (now == '*'){
                if (next == '.'){
                    visited[y][x] = 0;
                    box[y][x] = now;
                }
                else if (next == 'D'){
                    continue;
                }
            }
            else if (now == 'S'){
                visited[y][x] = visited[cur.first][cur.second] + 1;

                if (next == '.'){
                    box[y][x] = now;
                }
                else if (next == 'D'){
                    return ;
                }
            }
            q.push_back({y,x});
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

    cin >> n;
    cin >> m;

    int *ret;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < m; j++){
            box[i][j] = str.at(j);

            if (box[i][j] == 'S'){
                q.push_back({i,j});
                visited[i][j] = 0;
            }
            else if (box[i][j] == '*'){
                q.push_front({i,j});
                visited[i][j] = 0;
            }
            else if (box[i][j] == 'D'){
                ret = &visited[i][j];
            }
        }
    }

    bfs();
    
    if (*ret == -1)
    cout << "KAKTUS";
    else 
    cout << *ret;
}
