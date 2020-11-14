//
// Created by LeeChanYoung on 2020/11/07.
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

int N, M;

int parent[1000 * 1000];
int ans = 0;

int find(int id) {
    if (parent[id] < 0) return id;

    return parent[id] = find(parent[id]);
}

void uni(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) {
        return;
    }

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

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < M; ++j) {
            if (str[j] == 'U') {
                uni(i*M+j, (i-1)*M+j);
            } else if (str[j] == 'D') {
                uni(i*M+j, (i+1)*M+j);
            } else if (str[j] == 'L') {
                uni(i*M+j, i*M+(j-1));
            } else if (str[j] == 'R') {
                uni(i*M+j, i*M+(j+1));
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (parent[i*M+j] < 0)
                ans++;
        }
    }

    cout << ans;
}