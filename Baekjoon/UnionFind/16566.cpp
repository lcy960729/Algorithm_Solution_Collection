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

int parent[4000001] = {};

int find(int id) {
    if (parent[id] < 0)
        return id;

    return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

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

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> cards(M);
    for (auto &i : cards) {
        cin >> i;
    }

    sort(cards.begin(), cards.end());

    vector<int> queries(K);
    for (auto &i : queries) {
        cin >> i;

        int l = -1, r = M - 1, m;

        while (l + 1 < r) {
            m = (l + r) / 2;

            if (i < find(cards[m])) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << find(cards[r]) << "\n";
        uni(cards[r - 1], cards[r]);
    }
}