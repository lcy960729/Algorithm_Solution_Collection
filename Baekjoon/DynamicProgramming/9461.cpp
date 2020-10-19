#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long memo[1000];


//
//long long dp(int n)
//{
//    long long &memoVal = memo[n];
//
//    if (n < 3)
//    {
//        return 1;
//    }
//    else if (n >= 3 && n < 5)
//    {
//        return 2;
//    }
//
//    if (memoVal != -1)
//    {
//        return memoVal;
//    }
//
//    long long ret = dp(n - 1) + dp(n - 5);
//    memoVal = ret;
//
//    return ret;
//}


long long dp(int n)
{
    long long &memoVal = memo[n];

    if (n <= 3)
    {
        return 1;
    }

    if (memoVal != -1)
    {
        return memoVal;
    }

    long long ret = dp(n - 2) + dp(n - 3);
    memoVal = ret;

    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int arr[100];

    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp(arr[i]) << "\n";
    }
}