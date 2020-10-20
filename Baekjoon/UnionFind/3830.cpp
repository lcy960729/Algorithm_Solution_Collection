//
// Created by lcy96 on 2020-09-21.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[100001];
ll dist[100001] = {};

int find(int id) {
    if (parent[id] == -1)
        return id;

    int temp = find(parent[id]);
    dist[id] += dist[parent[id]];
    return parent[id] = temp;
}

void uni(int a, int b, int diff) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    dist[parentB] = dist[a] - dist[b] + diff;
    parent[parentB] = parentA;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        memset(parent, -1, sizeof(parent));
        memset(dist, 0, sizeof(dist));

        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < m; i++) {
            char op;
            cin >> op;

            int a, b, c;
            cin >> a >> b;

            if (op == '!') {
                cin >> c;
                uni(a, b, c);
            } else {
                if (find(a) == find(b))
                    cout << dist[b] - dist[a] << "\n";
                else
                    cout << "UNKNOWN\n";
            }
        }
    }
}