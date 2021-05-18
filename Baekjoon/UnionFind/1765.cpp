#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[1001];
int enemies[1001] = {};

int find(int id) {
    if (parent[id] < 0) return id;

    return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    parent[parentA] += parent[parentB];
    parent[parentB] = parentA;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));

    int n;
    cin >> n;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        char relation;
        int p, q;

        cin >> relation >> p >> q;

        if (relation == 'F') {
            uni(p, q);
        } else {
            if (enemies[p]) uni(enemies[p], q);
            if (enemies[q]) uni(enemies[q], p);

            enemies[p] = q;
            enemies[q] = p;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (parent[i] < 0) ans++;
    }

    cout << ans << '\n';
}