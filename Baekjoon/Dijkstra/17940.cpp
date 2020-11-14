//
// Created by LeeChanYoung on 2020/11/07.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;
int company[1001];
bool fin[1001] = {};
int dist[1001];
int trans[1001];

vector<pii > g[1001];

struct temp {
    int weight;
    int node;
    int count;
};

struct cmp {
    bool operator()(temp tmp1, temp tmp2) {
        if (tmp1.count == tmp2.count) {
            return tmp1.weight > tmp2.weight;
        }

        return tmp1.count > tmp2.count;
    }
};

void dijk() {
    priority_queue<temp, vector<temp>, cmp> pq;
    pq.push({0, M, 0});
    dist[M] = 0;
    trans[M] = 0;

    while (!pq.empty()) {
        temp cur = pq.top();
        int curNode = cur.node;

        pq.pop();

        if (fin[curNode])
            continue;

        for (pii next : g[curNode]) {
            int nextNode = next.first;
            int weight = next.second;
            int nextCount = cur.count;

            if (company[curNode] != company[nextNode])
                nextCount++;

            if (dist[nextNode] >= dist[curNode] + weight) {
                if (trans[nextNode] < nextCount)
                    continue;

                dist[nextNode] = dist[curNode] + weight;
                trans[nextNode] = nextCount;
                pq.push({dist[nextNode], nextNode, trans[nextNode]});
            }
        }
        fin[curNode] = true;
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

    fill(dist, dist + N, 1e9);
    fill(trans, trans + N, 1e9);

    for (int i = 0; i < N; ++i) {
        cin >> company[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k;
            cin >> k;

            if (k != 0) {
                g[i].push_back({j, k});
                g[j].push_back({i, k});
            }
        }
    }

    dijk();
    cout << trans[0] << " " << dist[0];
}