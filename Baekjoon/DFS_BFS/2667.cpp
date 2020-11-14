#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int square[26][26];
bool visited[26][26];

int home[626];
int cnt = 0;

void bfs(pair<int, int> start)
{
    queue<pair<int, int>> bfs;
    bfs.push(start);
    visited[start.first][start.second] = true;

    pair<int, int> cur;
    while (!bfs.empty())
    {
        home[cnt]++;
        cur = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> nextDir = cur;

            switch (i)
            {
            case 0:
                nextDir.second--;
                break;
            case 1:
                nextDir.first++;
                break;
            case 2:
                nextDir.second++;
                break;
            case 3:
                nextDir.first--;
                break;
            }

            int x = nextDir.first;
            int y = nextDir.second;

            if (visited[x][y] || !square[x][y])
                continue;

            visited[x][y] = true;
            bfs.push(nextDir);
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

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            square[i][j] = str.at(j) - '0';
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i][j] || !square[i][j])
                continue;

            bfs({i,j});
            cnt++;
        }
    }

    sort(home, home+cnt);

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++){
        cout << home[i] << "\n";
    }
}