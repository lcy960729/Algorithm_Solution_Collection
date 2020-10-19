#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
#define plli pair<ll, int>
#define pii pair<int, int>

using namespace std;

int N, E, v1, v2;
vector<pii> node[802];

ll dist[802];

void dijk(int start)
{
    priority_queue<plli> pq;

    fill(dist, dist + N+1, 17e10);

    bool finished[802] = {};

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        pq.pop();

        if (finished[cur])
            continue;

        for (plli x : node[cur])
        {
            int next = x.second;
            ll weight = x.first;

            if (dist[next] > dist[cur] + weight)
            {
                dist[next] = dist[cur] + weight;
                pq.push({-dist[next], next});
            }
        }

        finished[cur] = true;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back({c, b});
        node[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    ll ans = 0, v1ToV2 = 0, v2ToV1 = 0;

    dijk(v1);
    v1ToV2 = dist[1] + dist[v2];
    dijk(v2);
    v1ToV2 += dist[N];

    dijk(v2);
    v2ToV1 = dist[1] + dist[v1];
    dijk(v1);
    v2ToV1 += dist[N];

    ans = min(v1ToV2, v2ToV1);

    if (ans >= 17e10)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}
