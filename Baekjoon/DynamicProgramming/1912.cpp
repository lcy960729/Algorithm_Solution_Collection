#include <iostream>
#include <algorithm>

using namespace std;

int memo[100001];
int arr[100001];

long long dp(int n){
    long long ret = arr[n];

    if (n == 0){
        return arr[0];
    }

    if (memo[n] != 1e8+1){
        return memo[n]; 
    }


    ret = max(ret, (arr[n] + dp(n-1)));

    memo[n] = ret;
    return memo[n];
}

int main(){
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        memo[i] = 1e8+1;
    }

    long long ret = -1000;
    for (int i = 0; i < n; i++){
        ret = max(ret, dp(i));
    }

    cout << ret;

    return 0;
}