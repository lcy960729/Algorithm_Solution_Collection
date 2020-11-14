#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int T, N, M, K;

int dist[101][10001];
int fin[101][10001];

struct ticket{
    int d, c, w;
};

vector<ticket> node[101];

void dijk()
{
    priority_queue<pair<int, pii>> pq;

    dist[1][M] = 0;
    pq.push({-dist[1][M], {M, 1}});

    while (!pq.empty())
    {
        int nowNode = pq.top().second.second;
        int nowCost = pq.top().second.first;
        pq.pop();

        if (fin[nowNode][nowCost])
            continue;

        for (ticket next : node[nowNode])
        {
            int nextNode = next.d;
            int weight = next.w;

            int remainingCost = nowCost - next.c;

            if (remainingCost < 0)
                continue;

            if (dist[nextNode][remainingCost] > dist[nowNode][nowCost] + weight)
            {
                dist[nextNode][remainingCost] = dist[nowNode][nowCost] + weight;

                pq.push({-dist[nextNode][remainingCost], {remainingCost, nextNode}});
            }
        }

        fin[nowNode][nowCost] = true;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M >> K;

        for (int j = 0; j <= N; j++)
        {
            node[j].clear();
            fill(dist[j], dist[j] + M + 1, 1e9);
            fill(fin[j], fin[j] + M + 1, false);
        }

        for (int j = 0; j < K; j++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;

            node[u].push_back({v,c,d});
        }

        dijk();

        int ans = 1e9;
        for (int i = 0; i <= M; i++)
            ans = min(ans, dist[N][i]);
        

        if (ans == 1e9)
            cout << "Poor KCM" << "\n";
        else
            cout << ans << "\n";
    }
}