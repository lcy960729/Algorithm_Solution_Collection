//
// Created by lcy96 on 2020-09-29.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <tuple>

#define pii pair<int, int>
#define tii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
int parent[3001] = {};
pii point[3001][2] = {};

int find(int id) {
    if (parent[id] < 0)
        return id;

    parent[id] = find(parent[id]);
    return parent[id];
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    parent[parentA] += parent[parentB];
    parent[parentB] = parentA;
}

ll ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    ll ret = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);

    if (ret < 0)
        return -1;
    else if (ret > 0)
        return 1;
    else
        return 0;
}

bool isCross(pii pi[2], pii pj[2]) {
    int x1 = pi[0].first;
    int y1 = pi[0].second;
    int x2 = pi[1].first;
    int y2 = pi[1].second;
    int x3 = pj[0].first;
    int y3 = pj[0].second;
    int x4 = pj[1].first;
    int y4 = pj[1].second;

    if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
        ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {

        if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||
            (x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2))
            return false;
        else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||
                 (y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2))
            return false;
        else
            return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        point[i][0] = {x1, y1};
        point[i][1] = {x2, y2};
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (isCross(point[i], point[j])) {
                uni(i, j);
            }
        }
    }

    int numOfSet = 0;
    int maxSetSize = 1e9;

    for (int i = 0; i < N; ++i) {
        if (parent[i] < 0) {
            numOfSet++;
            maxSetSize = min(maxSetSize, parent[i]);
        }
    }

    cout << numOfSet << "\n" << -maxSetSize << "\n";
}