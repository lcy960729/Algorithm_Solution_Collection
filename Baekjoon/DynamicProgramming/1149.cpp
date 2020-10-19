#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[1000][3];
int memo[1000][3];


int dp(int n, int color)
{
    int &memoValue = memo[n][color];

    if (n == 0)
        return arr[n][color];

    if (memoValue != -1)
    {
        return memoValue;
    }

    int ret = 0;
    ret = arr[n][color] + min(dp(n-1, (color+1) % 3), dp(n-1, (color+2) % 3));
    
    memoValue = ret;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }

    cout << min(min(dp(n-1,0), dp(n-1,1)), dp(n-1,2));
}