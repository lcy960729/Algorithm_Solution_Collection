//
// Created by LeeChanYoung on 2021/01/30.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18
#define MAX 10001

using namespace std;

int id, d[MAX];
bool fin[MAX];
vector<int> a [MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x){
    d[x] = ++id;
    s.push(x);

    int parent = d[x];
    for (int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];

        if (d[y] == 0)
            parent = min(parent, dfs(y));
        else if (!fin[y])
            parent = min(parent, d[y]);
    }

    if (parent == d[x]) {
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();

            scc.push_back(t);
            fin[t] = true;

            if (t == x) break;
        }
        SCC.push_back(scc);
    }

    return parent;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v = 11;

    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(9);
    a[8].push_back(10);
    a[9].push_back(11);
    a[10].push_back(3);
    a[11].push_back(8);

    for (int i = 1; i <= v; ++i) {
        if (d[i] == 0) dfs(i);
    }

    for (int i = 0; i < SCC.size(); ++i) {
        cout << i+1 << '번\n';
        for (int j = 0; j < SCC[i].size(); ++j) {
            cout << SCC[i][j];
        }
        cout << '\n';
    }
}