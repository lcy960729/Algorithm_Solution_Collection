#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

int TC, N, M, W;

vector<pii> node[501];
int dist[501];
bool cycle;

void bf()
{
    dist[1] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (pii next : node[j])
            {
                if (dist[next.first] > dist[j] + next.second){
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

    cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        fill(dist, dist + 501, 1e9);
        for (int i = 0; i < 501; i++)
        {
            node[i].clear();
        }
        cycle = false;

        cin >> N >> M >> W;

        for (int j = 0; j < M + W; j++)
        {
            int S, E, T;
            cin >> S >> E >> T;

            if (j < M)
            {
                node[S].push_back({E, T});
                node[E].push_back({S, T});
            }
            else
            {
                for (int i = 0; i < node[S].size(); i++){
                    if (node[S].at(i).first == E)
                        node[S].erase(node[S].begin()+i);
                }

                node[S].push_back({E, -T});
            }
        }

        bf();

        if (cycle)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}