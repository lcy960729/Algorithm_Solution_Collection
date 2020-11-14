//
// Created by lcy96 on 2020-09-29.
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

int memo[10][1001];

int dp(int pre, int length){
    if (length == 0) {
        return 1;
    }

    int &ret = memo[pre][length];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = pre; i < 10; i++){
        ret += dp(i, length-1) % 10007;
    }

    return ret % 10007;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> N;

    cout << dp(0,N);
}
