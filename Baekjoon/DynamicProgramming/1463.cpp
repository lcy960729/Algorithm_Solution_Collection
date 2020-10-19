#include <iostream>
#include <algorithm>

using namespace std;

long long memo[1000001];

long long dp(int n){
    int min = 2e9;

    if (n == 1){
        return 0;
    }

    if (memo[n] != 0) 
        return memo[n];

    if (n % 2 == 0){
        if (memo[n/2] != 0)
            min = min > memo[n/2] + 1? memo[n/2] + 1 : min;
        else
            min = min > dp(n/2) + 1 ? dp(n/2) + 1 : min;
    }

    if (n % 3 == 0){
        if (memo[n/3] != 0)
            min = min > memo[n/3] + 1 ? memo[n/3] + 1 : min;
        else
            min = min > dp(n/3) + 1 ? dp(n/3) + 1 : min;
    }

    if (memo[n-1] != 0)
        min = min > memo[n-1] + 1? memo[n-1] + 1 : min;
    else
        min = min > dp(n-1) + 1 ? dp(n-1) + 1 : min;

    memo[n] = min;

    return memo[n];
}

int main(){
    int n;
    cin >> n;
 
    cout << dp(n);

    return 0;
}

