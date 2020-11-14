//
// Created by lcy96 on 2020-10-08.
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
int arr[1001];
int memo[1001];
int memo2[1001];

int dp(int cur){

    int &ret = memo[cur];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = cur-1; i >= 0; i--){
        if (arr[cur] > arr[i]){
            ret = max(ret, dp(i) + 1);
        }
    }

    return ret;
}

int dp2(int cur){

    int &ret = memo2[cur];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = cur+1; i < N; i++){
        if (arr[cur] > arr[i]){
            ret = max(ret, dp2(i) + 1);
        }
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
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < N; i++) {
        dp(i);
    }

    memset(memo2, -1, sizeof(memo2));

    for(int i = 0; i < N; i++) {
        dp2(i);
    }

    int result = 0;
    for (int i = 0; i < N; i++){
        result = max(result, memo[i] + memo2[i] +1);
    }

    cout << result << "\n";
}
