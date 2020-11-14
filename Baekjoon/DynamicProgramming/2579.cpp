#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[300];
int memo[300][2];

long long dp(int n, int count)
{
    int &memoValue = memo[n][count];

    if (n == 0)
        return arr[n];

    if (n < 0)
        return 0;

    if (memoValue != -1)
    {
        return memoValue;
    }

    long long ret;
    if (count == 1)
    {
        ret = dp(n - 2, 0);
    }
    else
    {
        ret = max(dp(n - 1, count + 1), dp(n - 2, 0));
    }

    ret += arr[n];
    memoValue = ret;

    return ret;
}

int main()
{
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << dp(n - 1, 0);
}