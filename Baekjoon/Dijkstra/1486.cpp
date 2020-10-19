//
// Created by CY on 2020-09-09.
//
//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Node{
    int x, y, time;
};

struct cmp{
    bool operator()(Node n1, Node n2){
        return n1.time > n2.time;
    }
};

int dx[] = {0, 1, 0 , -1};
int dy[] = {1, 0, -1 , 0};

int n, m , t, d;


int map[25][25];

int charToHeight(char c){
    int result;
    if (c >= 'A' && c <= 'Z')
        result = c - 'A';
    else
        result = c - 'a' + 26;

    return result;
}

int getTime(int nowX, int nowY, int nextX, int nextY){
    int nowHeight = map[nowX][nowY];
    int nextHeight = map[nextX][nextY];

    if (nowHeight >= nextHeight){
        return 1;
    }else{
        return (nextHeight-nowHeight) * (nextHeight-nowHeight);
    }
}

void dijk(pii start, int (*time)[25]){
    priority_queue<Node, vector<Node>, cmp> pq;
    bool fin[25][25] = {};

    pq.push({start.first, start.second});
    time[start.first][start.second] = 0;

    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();

        if (fin[now.x][now.y])
            continue;

        for (int i = 0; i < 4; i++){
            int nextX = now.x + dx[i];
            int nextY = now.y + dy[i];

            int weight = getTime(now.x, now.y, nextX, nextY);

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;

            if (abs(map[nextX][nextY] - map[now.x][now.y]) > t)
                continue;

            if (time[nextX][nextY] > time[now.x][now.y] + weight){
                time[nextX][nextY] = time[now.x][now.y] + weight;

                pq.push({nextX, nextY, time[nextX][nextY]});
            }
        }

        fin[now.x][now.y] = true;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t >> d;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            map[i][j] = charToHeight(s[j]);
        }
    }

    int time[25][25];
    int time_back[25][25];
    for (int i = 0; i < n; i++){
        fill(time[i], time[i]+m, 1e9);
        fill(time_back[i], time_back[i]+m, 1e9);
    }

    dijk({0,0}, time);

    vector<pii> temp;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (time[i][j] <= d) {
                temp.push_back({i,j});
            }
        }
    }

    int ans = 0;
    for (pii start : temp){
        for (int i = 0; i < n; i++) {
            fill(time_back[i], time_back[i] + m, 1e9);
        }

        dijk({start.first, start.second}, time_back);

        if (time_back[0][0] + time[start.first][start.second] <= d) {
            ans = max(ans, map[start.first][start.second]);
        }
    }

    cout << ans;
}