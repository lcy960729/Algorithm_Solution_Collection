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
int parent[300001] = {};
bool visited[300001] = {};

int n, l;

int find(int id){
    if (parent[id] == id)
        return id;

    parent[id] = find(parent[id]);
    return parent[id];
}

void uni(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    parent[parentA] = parentB;

    cout << "LADICA\n";
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));

    cin >> n >> l;

    for (int i = 1; i <= l; i++){
        parent[i] = i;
    }

    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if (!visited[a]){
            visited[a] = true;
            uni(a, b);
        }else if (!visited[b]){
            visited[b] = true;
            uni(b, a);
        }else if (!visited[find(parent[a])]){
            visited[find(parent[a])] = true;
            uni(a, b);
        }else if (!visited[find(parent[b])]){
            visited[find(parent[b])] = true;
            uni(b, a);
        }else{
            cout << "SMECE\n";
        }
    }
}