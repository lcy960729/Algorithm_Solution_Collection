#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Clazz {
    int id;
    string name;
    int startTime;
    int endTime;

    bool operator<(Clazz clazz) const {
        if (this->startTime == clazz.startTime) {
            return this->name < clazz.name;
        }

        return this->startTime < clazz.startTime;
    }
};

int N, M;
map<string, int> id;
vector<Clazz> clazzes;
vector<vector<pii>> g;

int timeToInt(string &s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string intToTime(int time) {
    return (time / 60 < 10 ? "0" + to_string(time / 60) : to_string(time / 60)) +
           ":" +
           (time % 60 < 10 ? "0" + to_string(time % 60) : to_string(time % 60));

}

bool fin[501] = {};
int dist[501];

void dijk(Clazz &start) {
    priority_queue<pii > pq;
    pq.push({start.endTime - start.startTime, start.id});
    dist[start.id] = start.endTime - start.startTime;

    int ans = 0;

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        //비용 내가 들을 수 있는 강의 시간
        //끝나는 시간 - 시작 시간 ( 시작 < 도착 시작 시간은 = 도착 시간)

        int curNode = cur.second;
        ans = max(ans, cur.first);

        for (pii next : g[curNode]) {
            int nextNode = next.first;
            int cost = next.second;

            int startTime = clazzes[nextNode].startTime;

            if (clazzes[curNode].endTime + cost > clazzes[nextNode].startTime) {
                startTime = clazzes[curNode].endTime + cost;
            }

            int endTime = clazzes[nextNode].endTime;

            int newDist = endTime - startTime;

            if (dist[nextNode] < dist[curNode] + newDist) {
                dist[nextNode] = dist[curNode] + newDist;
                pq.push({dist[nextNode], nextNode});
            }
        }

    }

    cout << intToTime(ans) << '\n';
}

int dist2[501][501];

void floyd() {
    for (int i = 0; i < N; ++i) {
        dist2[i][i] = 0;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist2[i][j] > dist2[i][k] + dist2[k][j]) {
                    dist2[i][j] = dist2[i][k] + dist2[k][j];
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    g.assign(N, vector<pii >());
    clazzes.assign(N, {});

    for (int i = 0; i < N; ++i) {
        string name, s, e;
        cin >> name >> s >> e;

        int startTime = timeToInt(s);
        int endTime = timeToInt(e);

        id[name] = i;
        clazzes[i] = {i, name, startTime, endTime};
    }

    for (int i = 0; i < N; ++i) {
        fill(dist2[i], dist2[i] + N, 1e9);
    }

    for (int i = 0; i < M; ++i) {
        string u, v, w;
        cin >> u >> v >> w;

        int uId = clazzes[id[u]].id;
        int vId = clazzes[id[v]].id;

        dist2[uId][vId] = min(dist2[uId][vId], timeToInt(w));
        dist2[vId][uId] = min(dist2[vId][uId], timeToInt(w));
    }

    floyd();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist2[i][j] == 1e9 || dist2[i][j] == 0) {
                continue;
            }

            g[i].push_back({j, dist2[i][j]});
        }
    }

    memset(fin, false, sizeof(fin));
    fill(dist, dist + N, 0);

    vector<Clazz> temp(clazzes);
    sort(temp.begin(), temp.end());

    dijk(*temp.begin());
}