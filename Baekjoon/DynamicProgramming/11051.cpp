//
// Created by CY on 2020-10-07.
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

int N, K;

int dp[1001][1001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= N; j++){
            if (i == j || j == 0){
                dp[i][j] = 1;
            }else{
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
            }
        }
    }

    cout << dp[N][K];
}