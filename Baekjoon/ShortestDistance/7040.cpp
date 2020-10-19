#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, ML, MD;

vector<pii> node[1001];
int dist[1001];
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

void spfa(){
    int cnt[1011]={};
    int inq[1011]={};

    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        inq[now] = false;

        if (++cnt[now] == N){
            cycle = true;
            break;
        }

        for (pii next : node[now]){
            if (dist[next.first] > dist[now] + next.second){
                dist[next.first] = dist[now] + next.second;

                if (!inq[next.first]){
                    q.push(next.first);
                    inq[next.first] = true;
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

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> ML >> MD;

    for (int i = 0; i < ML+MD; i++)
    {
        int A, B, D;
        cin >> A >> B >> D;

        if (i < ML)
            node[A].push_back({B, D});
        else
            node[B].push_back({A, -D});
    }

    fill(dist, dist + 1001, 1e9);
    cycle = false;

    //bf();
    spfa();
    
    if (dist[N] == 1e9)
        cout << -2 << "\n";
    else if (cycle)
        cout << -1 << "\n";
    else
        cout << dist[N] << "\n";
}