//
// Created by lcy96 on 2020-09-14.
//
#include <iostream>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
int map[17][17];
int memo[16][1<<16];

int dp(int current, int visited){
    int &ret = memo[current][visited];

    if (ret != -1){
        return ret;
    }

    if (visited == (1<<N)-1){
        if (map[current][0] != 0)
            return map[current][0];

        return 1e9;
    }

    ret = 1e9;
    for (int i = 0; i < N; i++){
        if (visited & (1 << i) || map[current][i] == 0)
            continue;

        ret = min(ret, dp(i, visited | (1<<i)) + map[current][i]);
    }

    return ret;
}

int main(){

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0,1) << '\n';
}