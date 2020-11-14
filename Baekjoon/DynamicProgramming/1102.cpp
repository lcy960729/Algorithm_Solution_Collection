//
// Created by lcy96 on 2020-10-21.
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

int N, P;

int cost[16][16];
char state[16];

int memo[65536][16];

int dp(int pre, int state) {
    if (__builtin_popcount(state) >= P) {
        return 0;
    }

    int &ret = memo[state][pre];
    if (ret != -1)
        return ret;

    ret = 1e9;
    for (int i = 0; i < N; i++) {
        if ((state & (1 << i)) == 0) // N일때
            continue;

        for (int j = 0; j < N; j++) {
            if ((state & (1 << j)) != 0) // Y일때
                continue;

            state |= (1 << j);
            ret = min(ret, dp(j, state) + cost[i][j]);
            state &= ~(1 << j);
        }
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    int numOfOk = 0;
    int initState = 0;
    for (int i = 0; i < N; i++) {
        cin >> state[i];

        if (state[i] == 'Y') {
            numOfOk++;
            initState |= (1 << i);
        }
    }

    cin >> P;

    int ans = dp(0, initState);

    if (ans == 1e9){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
}
