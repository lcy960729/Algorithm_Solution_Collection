#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool arr[101];
long long memo[101][41];
int N;

long long dp(int n, int coupon)
{
    if (n > N)
    {
        return 0;
    }

    long long  &memoValue = memo[n][coupon];
    if (memoValue != -1)
    {
        return memoValue;
    }

    long long ret = 0;
    if (arr[n] == false){
        ret = dp(n+1, coupon);
    }else
    {
        long long temp = min({10000+dp(n+1, coupon), 25000+dp(n+3, coupon + 1), 37000+dp(n+5, coupon + 2)});
        
        if (coupon >= 3)
            temp = min(temp, dp(n+1, coupon-3));
    
        ret = temp;
    }

    memoValue = ret;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(arr, true, sizeof(arr));
    memset(memo, -1, sizeof(memo));

    cin >> N;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int index;
        cin >> index;
        arr[index] = false;
    }

    cout << dp(1, 0) << endl;
}