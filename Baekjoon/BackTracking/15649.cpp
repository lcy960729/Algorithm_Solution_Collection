//
// Created by lcy96 on 2020-09-23.
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
vector<int> answer;
bool selected[9]={};

void dfs(int id){
    if (id == M){

        for (int x : answer)
            cout << x << " ";

        cout << "\n";

        return;
    }

    for (int i = 1; i <= N; ++i){
        if (selected[i])
            continue;

        answer.push_back(i);
        selected[i] = true;
        dfs(id + 1);

        answer.pop_back();
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

    dfs(0);
}