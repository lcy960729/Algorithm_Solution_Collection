//
// Created by lcy96 on 2020-09-28.
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
bool selected[9] = {};

void dfs(int index, int cnt){
    if (cnt == M){
        for (int i = 1; i <= N; ++i){
            if (selected[i])
                cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = index+1; i <= N; ++i){
        if (selected[i])
            continue;

        selected[i] = true;
        dfs(i, cnt+1);
        selected[i] = false;
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    dfs(0, 0);
}