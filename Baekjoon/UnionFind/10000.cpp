//
// Created by CY on 2020-10-06.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int parent[300001];

int find(int id){
    if (parent[id] < 0){
        return id;
    }

    parent[id] = find(parent[id]);
    return parent[id];
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

    memset(parent, -1, sizeof(parent));

    int N;
    cin >> N;

    map<int, int> mp;
    int cnt = 0;

    int answer = N+1;

    while(N--){
        int a, b;
        cin >> a >> b;

        int l = a - b;
        int r = a + b;

        if (mp.find(l) == mp.end()){
            mp[l] = cnt++;
        }

        if (mp.find(r) == mp.end()){
            mp[r] = cnt++;
        }

        if (find(mp[l]) == find(mp[r])){
            answer++;
        }else{
            uni(mp[l], mp[r]);
        }
    }

    cout << answer;
}