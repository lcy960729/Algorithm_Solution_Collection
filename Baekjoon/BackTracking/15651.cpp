//
// Created by CY on 2020-09-28.
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

void dfs(int cnt){
    if (cnt == M){
        for (int x: answer){
            cout << x << " ";
        }
        cout << "\n";
        return ;
    }

    for (int i = 1; i <= N; i++){
        if (!answer.empty() && answer.back() > i){
            continue;
        }

        answer.push_back(i);
        dfs(cnt+1);
        answer.pop_back();
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