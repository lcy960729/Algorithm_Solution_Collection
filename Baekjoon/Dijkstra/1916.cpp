#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

vector<pii> g[1001];
int dist[1001];

void dijk(int start){
    priority_queue<pii> pq;

    dist[start] = 0;
    pq.push({0, start});

    bool finished[1001]= {};

    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();

        if (finished[now])
            continue;

        for (pii x : g[now])
        {
            int nxt = x.second, w = x.first;

            if (dist[nxt] > dist[now] + w){
                dist[nxt] = dist[now] + w;
                pq.push({-dist[nxt], nxt});
            }
        }
        finished[now] = 1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int s, d, w;
        cin >> s >> d >> w;
        g[s].push_back({w, d});
    }

    fill(dist, dist + N+1, 1e9);

    int begin, end;
    cin >> begin >> end;

    dijk(begin);

    cout << dist[end] << "\n";
}