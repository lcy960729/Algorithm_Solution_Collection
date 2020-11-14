#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

#define pii pair<int, int>
#define tiii tuple<int, int, int>

int t;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

using namespace std;

int map[126][126];
int dist[126][126];


void dijk(pii start){
    bool finished[126][126] = {};

    priority_queue<tiii> pq;

    int startY = start.first;
    int startX = start.second;

    dist[startY][startX] = map[startY][startX];
    pq.push({map[startY][startX], startY, startX});

    while(!pq.empty()){
        tiii now = pq.top();
        pq.pop();

        int nowY = get<1>(now);
        int nowX = get<2>(now);

        if (finished[nowY][nowX]){
            continue;
        }

        for (int i = 0; i < 4; i++){
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (nextX < 0 || nextX > t-1 || nextY < 0 || nextY > t-1)
                continue;

            if (dist[nextY][nextX] > dist[nowY][nowX] + map[nextY][nextX]){
                dist[nextY][nextX] = dist[nowY][nowX] + map[nextY][nextX];
                pq.push({-dist[nextY][nextX], nextY, nextX});
            }
        }
        finished[nowY][nowX] = true;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int caseCount = 0;
    while (true){        
        cin >> t;
        
        fill((int*)dist, (int*)(dist+t), 1e9);

        if (t == 0)
            return 0;
        
        caseCount++;

        for (int i = 0; i < t; i++){
            for (int j = 0; j < t; j++)
                cin >> map[i][j];
        }

        dijk({0,0});

        cout << "Problem " << caseCount << ": " << dist[t-1][t-1] << "\n";;
    }

}