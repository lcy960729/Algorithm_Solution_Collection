#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, M;

int dist[251][251];

void floyd()
{
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 251; i++)
        fill(dist[i], dist[i] + 251, 1e9);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        
        dist[u][v] = 0;

        if (b == 0){
            dist[v][u] = 1;
        }else{
            dist[v][u] = 0;
        }
    }

    floyd();

    int k;
    cin >> k;

    for (int i = 0; i < k; i++){
        int s, e;
        cin >> s >> e;

        cout << dist[s][e] << "\n";
    }
}