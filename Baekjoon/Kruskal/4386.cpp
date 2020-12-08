//
// Created by LeeChanYoung on 2020/11/20.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct node{
    int u;
    int v;
    double w;

    bool operator<(const node &rhs) const {
        return w < rhs.w;
    }
};

int n;
int parent[101];
pdd p[101];

vector<node> g;

double find_distance(pdd p1, pdd p2){
    double dx = (p1.first - p2.first) *  (p1.first - p2.first);
    double dy = (p1.second - p2.second) *  (p1.second - p2.second);

    return sqrt(dx + dy);
}

int find(int id){
    if (parent[id] < 0){
        return id;
    }

    return parent[id] = find(parent[id]);
}

void uni(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    parent[parentA] += parent[parentB];
    parent[parentB] = parentA;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double dist = find_distance(p[i], p[j]);
            g.push_back({i,j,dist});
        }
    }

    sort(g.begin(), g.end());

    memset(parent, -1, sizeof(parent));

    double ans = 0;
    for (int i = 0; i < g.size(); i++){
        int u = g[i].u;
        int v = g[i].v;
        double w = g[i].w;

        if (find(u) != find(v)) {
            uni(u, v);
            ans += w;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;
}
