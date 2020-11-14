//
// Created by lcy96 on 2020-09-16.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct query{
    int x;
    int a;
    int b;
};

int parent[200001];
query queries[400002];
int parentValue[200001];

int find(int a){
    if (parent[a] == 0)
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

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n-1; i++){
        int a;
        cin >> a;

        parentValue[i+1] = a;
    }

    for (int i = 0; i < n-1+q; i++){
        int x;
        cin >> x;
        int a, b;

        if (x == 0){
            cin >> b;
            a = parentValue[b];
        }else{
            cin >> a >> b;
        }

        queries[i] = {x, a, b};
    }

    stack<string> answer;

    for (int i = (n-1+q)-1; i >= 0; i--){
        query &query = queries[i];

        if (query.x == 0){
            uni(query.a, query.b);
        }else{
            answer.push((find(query.a) == find(query.b) ? "YES" : "NO"));
        }
    }

    while(!answer.empty()){
        cout << answer.top() << "\n";
        answer.pop();
    }
}