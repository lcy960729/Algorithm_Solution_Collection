#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int N, M;

vector<pii> node[501];
long long dist[501];

bool cycle = false;

void bf()
{
    dist[1] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (pii next : node[j])
            {
                if (dist[j] == 3e18)
                    continue;

                if (dist[next.first] > dist[j] + next.second)
                {
                    dist[next.first] = dist[j] + next.second;

                    if (i == N)
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

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        node[A].push_back({B, C});
    }

    fill(dist, dist+ N + 1, 3e18);

    bf();

    if (cycle){
        cout << -1 << "\n";
    }else{
        for (int i = 2; i <=N; i++){
            if (dist[i] == 3e18)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";       
        }
    }
}
