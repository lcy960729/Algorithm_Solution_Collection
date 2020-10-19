#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int memo[1000];

int dp(int n)
{
    int &memoVal = memo[n];

    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }

    if (memoVal != -1)
    {
        return memoVal;
    }

    int ret = dp(n - 1) + dp(n - 2) + dp(n - 3);

    memoVal = ret;

    return ret;
}

int main()
{
    memset(memo, -1, sizeof(memo));

    int t;
    cin >> t;

    int arr[11];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
        memo[i] = -1;
    }

    for (int i = 0; i < t; i++)
    {
        cout << dp(arr[i]) << "\n";
    }
}