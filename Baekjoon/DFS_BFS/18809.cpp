#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define GREEN 3
#define RED 4
#define FLOWER 5
#define LAKE 0

using namespace std;

int n, m, g, r;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int box[51][51];
int visited[51][51];
int minuted[51][51];

queue<pair<int, int>> q;
vector<pair<int, int>> candidate;
vector<int> order;

void printlog()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(2);
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printlogM()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(2);
            cout << minuted[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int bfs()
{
    int flowers = 0;
    pair<int, int> cur;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = cur.second + dx[i];
            int y = cur.first + dy[i];

            if (x < 0 || x >= m)
                continue;

            if (y < 0 || y >= n)
                continue;

            int next = box[y][x];

            int visitedNow = visited[cur.first][cur.second];
            int visitedNext = visited[y][x];

            if (visitedNow == FLOWER || visitedNext == FLOWER || next == LAKE || visitedNow == visitedNext)
                continue;

            if ((visitedNow + visitedNext == RED + GREEN))
            {
                if ((minuted[y][x] == minuted[cur.first][cur.second] + 1)){
                    visited[y][x] = FLOWER;
                    flowers++;                   
                }
                continue;
            }

            visited[y][x] = visitedNow;
            minuted[y][x] = minuted[cur.first][cur.second] + 1;

            q.push({y, x});
        }
    }
    
    return flowers;
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
    memset(minuted, -1, sizeof(minuted));

    cin >> n;
    cin >> m;
    cin >> g;
    cin >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];

            if (box[i][j] == 2)
            {
                order.push_back(0);
                candidate.push_back({i,j});
            }
        }
    }
    
    for (int i = 0; i < g+r; i++){
        order.erase(order.begin());
        if (i < g)
            order.push_back(GREEN);
        else
            order.push_back(RED);
    }

    int ans = 0;
    do
    {
        for (int i = 0; i < order.size();i++){    
            if (order[i] == 0)
                continue;

            int x = candidate[i].second;
            int y = candidate[i].first;

            visited[y][x] = order[i]; 
            minuted[y][x] = 0;
            q.push({y,x});
        }

        ans = max(ans, bfs());
        //cout << ans << endl;;

        memset(visited, -1, sizeof(visited));
        memset(minuted, -1, sizeof(minuted));
    } while (next_permutation(order.begin(), order.end()));
    
    cout << ans << endl;
}
