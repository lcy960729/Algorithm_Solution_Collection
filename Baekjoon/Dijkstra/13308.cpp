#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

vector<pii> node[2501];
bool fin[2501][2501]={};
ll dist[2501][2501];

int cost[2501];

int N, M;

void dijk(){
    priority_queue<pair<ll, pair<int, int>>> pq;

    dist[1][cost[1]] = 0;
    pq.push({-dist[1][cost[1]], {cost[1],1}});
    
    while(!pq.empty()){
        int now = pq.top().second.second;
        int nowCost = pq.top().second.first;
        pq.pop();

        if (fin[now][nowCost])
            continue;

        for (pii next : node[now]){
            int nextNode = next.first;
            int weight = next.second;

            int minCost = min(nowCost, cost[now]);

            if (dist[nextNode][minCost] > dist[now][nowCost] + (weight * minCost)){
                dist[nextNode][minCost] = dist[now][nowCost] + (weight * minCost);

                pq.push({-dist[nextNode][minCost], {minCost, nextNode}});
            }
        }

        fin[now][nowCost] = true;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> N >> M;

    for (int i  = 1; i <= N; i++){
        cin >> cost[i];
    }

    for (int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;

        node[A].push_back({B, C});
        node[B].push_back({A, C});
    }

    for (int i = 0; i < 2501; i++){
        fill(dist[i], dist[i]+2501, 3e18);
    }

    dijk();
    
    ll ans = 3e18;    
    for(int i = 0; i < 2501; i++){
        if (dist[N][i] != 3e18)
        ans = min(ans, dist[N][i]);
    }
    
    cout << ans << "\n";
}