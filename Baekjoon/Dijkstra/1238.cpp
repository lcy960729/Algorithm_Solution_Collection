#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long
#define plli pair<ll, int>
#define pii pair<int, int>

using namespace std;

int N, M, X;
vector<pii> node1[1001];
vector<pii> node2[1001];

ll dist[1001];
ll ret[1001];

void dijk(int start, vector<pii> node[])
{
    priority_queue<plli> pq;

    fill(dist, dist + N + 1, 3e18);

    bool finished[1001] = {};

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
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node1[a].push_back({c, b});
        node2[b].push_back({c, a});
    }

    fill (ret, ret+N+1, 0);

    dijk(X, node1);
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == 3e18)
            continue;

        ret[i] += dist[i];
    }

    dijk(X, node2);
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == 3e18)
            continue;

        ret[i] += dist[i];
    }

    ll ans = 0;
    for (int i = 1; i <=N; i++ ){
        ans = max(ans , ret[i]);
    }

    cout << ans << "\n";
}
