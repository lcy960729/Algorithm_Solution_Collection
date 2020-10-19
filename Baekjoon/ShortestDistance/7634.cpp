#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, M, Q;

vector<pii> node[1001];

int dist[1001];

bool cycle;

void bf()
{
    dist[1] = 0;

    for (int i = 1; i <= N + M; i++)
    {
        for (int j = 1; j <= N + M; j++)
        {
            for (pii next : node[j])
            {
                if (dist[next.first] > dist[j] + next.second)
                {
                    dist[next.first] = dist[j] + next.second;

                    if (i == N + M)
                        cycle = true;
                }
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    while (true)
    {
        for (int i = 0; i < 1001; i++)
            node[i].clear();
        
        fill(dist, dist + N + M + 1, 1e9);
        cycle = false;

        cin >> N >> M >> Q;

        if (N == 0 && M == 0 && Q == 0)
            return 0;

        for (int i = 0; i < Q; i++)
        {
            int a, b, c;
            string op;

            cin >> a >> b >> op >> c;

            if (op == "<=")
                node[a].push_back({b+N, c});
            else
                node[b+N].push_back({a, -c});
        }

        bf();

        if (cycle)
            cout << "Impossible" << "\n";
        else
            cout << "Possible" << "\n";
    }
}