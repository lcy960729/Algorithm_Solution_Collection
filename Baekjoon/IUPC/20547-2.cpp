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

    bool operator<(const Clazz &clazz) const {
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

int memo[501];

int dp(int id) {
    int &ret = memo[id];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (pii next : g[id]) {
        int nextNode = next.first;

        int nextStartTime = clazzes[nextNode].startTime;
        int nextEndTime = clazzes[nextNode].endTime;

        int nowEndTime = clazzes[id].endTime + next.second;
        if (nowEndTime > nextStartTime) {
            nextStartTime = nowEndTime;
        }

        int totalTime = nextEndTime - nextStartTime;

        if (totalTime < 0)
            totalTime = 0;

        ret = max(ret, dp(nextNode) + totalTime);
    }

    return ret;
}

int dist[501][501];

void floyd() {
    for (int i = 0; i < N; ++i) {
        dist[i][i] = 0;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
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
        fill(dist[i], dist[i] + N, 1e9);
    }

    for (int i = 0; i < M; ++i) {
        string u, v, w;
        cin >> u >> v >> w;

        int uId = clazzes[id[u]].id;
        int vId = clazzes[id[v]].id;

        dist[uId][vId] = min(dist[uId][vId], timeToInt(w));
        dist[vId][uId] = min(dist[vId][uId], timeToInt(w));
    }

    floyd();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == 1e9 || dist[i][j] == 0) {
                continue;
            }

            g[i].push_back({j, dist[i][j]});
        }
    }

    memset(memo, -1, sizeof(memo));

    Clazz clazz = *min_element(clazzes.begin(), clazzes.end());
    cout << intToTime(dp(clazz.id) + clazz.endTime - clazz.startTime) << '\n';
}