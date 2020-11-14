#include <iostream>
#include <algorithm>
#include <queue>

#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int T, N, M, K;
vector<tiii> g[100001];

int h[100001];
long long dist[100001];
long long cost[100001];

bool finished[100001];

void dijk(int start, long long dist[]){
    priority_queue<tiii> pq;

    dist[start] = 0;
    pq.push({0, 0, start});

    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();

        if (finished[now])
            continue;

        for (pii x : g[now]){
            int next = x.second;
            int w = x.first;

            if (dist[next] > dist[now] + w){
                dist[next] = dist[now] + w;
                pq.push({-dist[next], next});
            }
        }
        finished[now] = true;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> N >> M >> K;

        for (int j = 0; i < K; j++){
            int u, v, c, d;
            cin >> u >> v >> c >> d;

            g[u].push_back({d,v});
        }
    }

    fill(dist, dist+N+1, 3e18);
    fill(finished, finished+N+1, false);

    dijk(1, dist);

    long long ret = -3e18;
    for (int i = 1; i <= N; i++){
        if (dist[i] == 3e18 || dist1[i] == 3e18)
            continue;

        ret = max(ret, h[i]*E - (dist[i]+dist1[i])*D);
    }

    if (ret == -3e18){
        cout << "Impossible" << "\n";
    }else{
        cout << ret << "\n";
    }
}