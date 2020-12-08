//
// Created by LeeChanYoung on 2020/11/27.
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

struct query {
    int index, B, C;
};

int N, M, K;

int mentor[100001];
int X[100001];
int order[100001];

vector<query> queries[100001];

int parent[100001];

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
    memset(order, -1, sizeof(order));

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> mentor[i];
    }

    for (int i = 1; i <= M; ++i) {
        cin >> X[i];

        if (order[X[i]] == -1) {
            order[X[i]] = i;
        }
    }

    for (int i = 0; i < K; ++i) {
        int A, B, C;
        cin >> A >> B >> C;

        queries[A].push_back({i, B, C});
    }

    vector<bool> answer(K);

    for (int i = 1; i <= N; ++i) {
        if (order[i] == -1 && mentor[i] != -1)
            uni(mentor[i], i);
    }

    for (int i = M; i >= 0; --i) {
        for (query &q : queries[i]) {
            answer[q.index] = find(q.B) == find(q.C);
        }

        if (i == order[X[i]]) {
            uni(mentor[X[i]], X[i]);
        }
    }

    for (bool ans : answer) {
        cout << (ans ? "Same Same;\n" : "No;\n");
    }
}