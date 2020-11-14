#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[501][501];
long long memo[501][501];
int N, M;

long long dp(int n, int m)
{
    long long &memoValue = memo[n][m];

    if (n == 0 && m == 0)
    {
        return 1LL;
    }

    if (memoValue != -1)
    {
        return memoValue;
    }

    long long ret = 0;

    if (arr[n][m] < arr[n][m - 1])
    {
        ret += dp(n, m - 1);
    }

    if (arr[n][m] < arr[n][m + 1])
    {
        ret += dp(n, m + 1);
    }

    if (arr[n][m] < arr[n - 1][m])
    {
        ret += dp(n - 1, m);
    }

    if (arr[n][m] < arr[n + 1][m])
    {
        ret += dp(n + 1, m);
    }

    memoValue = ret;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(memo, -1, sizeof(memo));
    memset(arr, 1e9, sizeof(arr));

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << dp(N - 1, M - 1) << endl;
}