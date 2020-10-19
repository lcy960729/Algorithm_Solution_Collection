#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[1001];

int dp(int n){
    int &memoValue = memo[n];

    if (n == 1){
        return 1;
    }else if (n == 2){
        return 3;
    }

    if (memoValue != -1){
        return memoValue;
    }

    int ret = (dp(n - 2) * 2 + dp(n - 1)) % 10007;

    memoValue = ret;
    return ret;
}

int main()
{
    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n;

    cout << dp(n);
}