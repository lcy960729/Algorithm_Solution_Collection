#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1000];
int memo[1000];
int N;

int dp(int n)
{
    int &memoValue = memo[n];

    if (n == N-1)
        return arr[n];

    if (memoValue != -1)
    {
        return memoValue;
    }

    int ret = 0;
    for (int i = n+1; i < N; i++){
        if (arr[n] >= arr[i])
            continue;

        ret = max(ret, dp(i));
    }
    ret += arr[n];

    memoValue = ret;
    return ret;
}

int main()
{
    cin >> N;
    memset(memo, -1, sizeof(memo));
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ret = -1;
    for (int i = 0; i < N; i++){
        ret = max(ret, dp(i));
    }
    cout << ret;
}