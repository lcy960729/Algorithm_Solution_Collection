#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, M, K;

vector<pii> node[1001];
priority_queue<int> dist[1001];

void dijk()
{
    priority_queue<pii> pq;
    dist[1].push(0);
    pq.push({0, 1});

    while (!pq.empty())
    {
        int nowNode = pq.top().second;
        int nowWeight = pq.top().first * -1;
        pq.pop();

        for (pii next : node[nowNode])
        {
            int nextNode = next.first;
            int nextWeight = next.second;

            if (dist[nextNode].size() < K){
                dist[nextNode].push(nowWeight + nextWeight);
                
                pq.push({-(nowWeight+nextWeight), nextNode});
            }
            else if (dist[nextNode].top() > nowWeight + nextWeight)
            {
                dist[nextNode].pop();
                dist[nextNode].push(nowWeight + nextWeight);

                pq.push({-(nowWeight+nextWeight), nextNode});
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back({b, c});
    }

    dijk();

    for (int i = 1; i <= N; i++)
    {
        if (dist[i].size() == K)
            cout << dist[i].top() << "\n";
        else
            cout << -1 << "\n";
    }
}