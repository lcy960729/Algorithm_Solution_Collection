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

int N;

bool col[15] = {};
bool row[15] = {};
bool diag1[30] = {};
bool diag2[30] = {};

int answer = 0;

void place(int y, int x){
    col[x] = row[y] = diag1[y+x] = diag2[y-x+N] = true;
}

void unPlace(int y, int x){
    col[x] = row[y] = diag1[y+x] = diag2[y-x+N] = false;
}

bool check(int y, int x){
    return !(col[x] || row[y] || diag1[y+x] || diag2[y-x+N]);
}

void dfs(int y){
    if (y == N){
        answer++;
        return;
    }

    for (int x = 0; x < N; ++x){
        if (check(y, x)) {
            place(y,x);
            dfs(y + 1);
            unPlace(y,x);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    dfs(0);

    cout << answer << "\n";
}
