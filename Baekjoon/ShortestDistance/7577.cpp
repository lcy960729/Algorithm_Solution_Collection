#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int K, N;

vector<pii> node[41];

int dist[41];

bool cycle;

void bf()
{
    dist[0] = 0;

    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            for (pii next : node[j])
            {
                if (dist[next.first] > dist[j] + next.second)
                {
                    dist[next.first] = dist[j] + next.second;

                    if (i == K)
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

    cin >> K >> N;

    for (int i = 0; i < N; i++)
    {
        int x, y, r;

        cin >> x >> y >> r;

        node[x-1].push_back({y, r});
        node[y].push_back({x-1, -r});
    }

    for (int i = 0; i < K; i++){
        node[i].push_back({i+1, 1});
        node[i+1].push_back({i, 0});
    }

    fill(dist, dist + K + 1, 1e9);
    cycle = false;

    bf();

    if (cycle)
        cout << "NONE"
             << "\n";
    else{
        for (int i = 1; i <= K; i++){
            cout << (dist[i]-dist[i-1] ? "#" : "-") << "";
        }
    }
}