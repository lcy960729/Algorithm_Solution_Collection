#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[10001][3];
int arr[10001];

int dp(int n, int count)
{
    int &memoValue = memo[n][count];

    if (n <= 0){
        if ( count < 2)
            return arr[n];
        else
             return 0;
    }

    if (memoValue != -1)
    {
        return memoValue;
    }

    int ret = 0;

    if (count == 2){
        ret = dp(n-1, 0);
    }else {
        ret = max (arr[n] + dp(n-1, count + 1), dp(n-1, 0));
    }

    memoValue = ret;
    return ret;
}

int main()
{
    memset(memo, -1, sizeof(memo));
    memset(arr, 0, sizeof(arr));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << dp(n, 0) << "\n";
}