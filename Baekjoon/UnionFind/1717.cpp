//
// Created by lcy96 on 2020-09-16.
//
#include <iostream>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[1000001] = {};

int find(int a){
    if (parent[a] == -1)
        return a;

    parent[a] = find(parent[a]);
    return parent[a];
}

void uni(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    parent[parentB] = parentA;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < m; i++){
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0){
            uni(a,b);
        }else{
            cout << (find(a) == find(b) ? "YES" : "NO") << "\n";
        }
    }
}