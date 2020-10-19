//
// Created by CY on 2020-09-18.
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
int memo[501][501];
int cost[501];
int preSum[501];

int dp(int a, int b){
    if (a == b)
        return cost[a];

    int &ret = memo[a][b];
    if (ret != -1)
        return ret;

    ret = 1e9;

    int sum =  preSum[b+1] - preSum[a];

    for (int i = a; i < b; i++){
        ret = min(ret, dp(a, i) + dp(i+1, b) + sum);
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

    for (int i = 0; i < N; i++) {
        memset(memo, -1, sizeof(memo));
        int num;	cin >> num;

        for (int j = 0; j < num; j++)
            cin >> cost[j];

        for (int j = 1; j <= num; j++)
            preSum[j] = preSum[j - 1] + cost[j-1];

        int ret = 1e9;

        for (int j = 0; j < num - 1; j++) {
            ret = min(ret, dp(0, j) + dp(j + 1, num - 1));
        }

        cout << ret << endl;
    }
}

