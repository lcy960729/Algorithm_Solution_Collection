//
// Created by lcy96 on 2020-09-22.
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

int n;
int arr[501][501];
int memo[501][501];


int dp(int y, int x){
    if (y == n-1){
        return arr[y][x];
    }

    int &ret = memo[y][x];
    if (ret != -1)
        return ret;

    ret = max(dp(y+1, x), dp(y+1, x+1)) + arr[y][x];
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    memset(arr, -1, sizeof(arr));
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i+1; j++){
            cin >> arr[i][j];
        }
    }

    cout << dp(0,0);

}