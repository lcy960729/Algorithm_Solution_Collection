#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[201];

int find(int id) {
    if (parent[id] < 0) return id;

    return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    parent[parentB] += parent[parentA];
    parent[parentA] = parentB;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int isConnected;
            cin >> isConnected;

            if (isConnected)
                uni(i, j);
        }
    }

    bool ans = true;
    int parentCity = -1;
    for (int i = 0; i < M && ans; ++i) {
        int city;
        cin >> city;

        city--;

        if (parentCity == -1)
            parentCity = find(city);
        else
            ans &= (find(city) == parentCity);
    }

    cout << (ans ? "YES" : "NO") << '\n';
}