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

int parent[10001] = {};
int cost[10001] = {};

int find(int a){
    if (parent[a] < 0)
        return a;

    parent[a] = find(parent[a]);
    return parent[a];
}

void uni(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB)
        return;

    int s, d;

    if (cost[parentA] > cost[parentB]){
        s = parentB;
        d = parentA;
    }else{
        s = parentA;
        d = parentB;
    }

    parent[s] += parent[d];
    parent[d] = s;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++){
        cin >> cost[i];
    }

    for (int i = 0; i < m; i++){
        int v, w;
        cin >> v >> w;

        uni(v, w);
    }

    int totalCost = 0;
    int numOfFriends = 0;
    for (int i = 1; i <= n; i++){
        if (parent[i] < 0){
            totalCost += cost[i];
            numOfFriends += -parent[i];
        }
    }

    if (totalCost <= k && numOfFriends == n){
        cout << totalCost << "\n";
    }else{
        cout << "Oh no" << "\n";
    }
}