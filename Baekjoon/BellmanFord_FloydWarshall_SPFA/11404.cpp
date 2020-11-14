#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

ll dist[101][101];

int N, M;

void floyd()
{
    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0;
    }

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

    cin >> N >> M;

    for (int i = 1; i <=N; i++)
    {
        fill(dist[i], dist[i] + N + 1, 3e18);
    }

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        dist[A][B] = min(dist[A][B], (ll)C);
    }

    floyd();

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == 3e18)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
