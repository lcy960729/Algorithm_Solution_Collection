#include <iostream>

using namespace std;

long long memo[91];

long long fibo(int n){
    if (n <= 1)
        return n;

    if (memo[n] != 0)
        return memo[n];

    memo[n] = fibo(n-1) + fibo(n-2);

    return memo[n];
}

int main(){
    int n;
    cin >> n;
 
    cout << fibo(n);

    return 0;
}

