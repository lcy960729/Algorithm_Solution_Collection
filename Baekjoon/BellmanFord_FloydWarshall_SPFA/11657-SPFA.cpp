#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long

using namespace std;

vector<pii> node[501];
ll dist[501];
int cnt[501];
bool inq[501];

bool cycle = false;

int N, M;

void spfa(){
    queue<int> q;

    dist[1] = 0;
    q.push({1});
    inq[1] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        inq[now] = false;

        cnt[now]++;
        if (cnt[now] == N){ 
            cycle = true;
            break;
        }

        for (pii nextNode: node[now]){
            int next = nextNode.first;
            int weight = nextNode.second;

            if (dist[next] > dist[now] + weight){
                dist[next] = dist[now] + weight;
            
                if (!inq[next]){
                    inq[next] = true;
                    q.push({next});
                }
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> N >> M;

    for (int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;

        node[A].push_back({B, C});
    }

    fill(dist, dist+N+1, 3e18);
    fill(cnt, cnt+N+1, 0);
    fill(inq, inq+N+1, false);

    spfa();

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
