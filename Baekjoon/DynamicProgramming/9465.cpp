#include<iostream>
#include<algorithm>
#include <cstring>

using namespace std;

int arr[2][100000];
int memo[2][100000];

int dp(int m, int n){
    int &memoValue = memo[m][n];

    if (n < 1)
    {
        return arr[m][n];
    }

    if (memoValue != -1)
    {
        return memoValue;
    }

    int ret = 0;
    int next_m = (m+1) % 2;

    ret = arr[m][n] + max(dp(next_m, n-1), dp(next_m, n-2));

    memoValue = ret;
    return ret;
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        memset(memo, -1, sizeof(memo));
        memset(arr, 0, sizeof(arr));

        int n;
        cin >> n;

        for (int j = 0; j < 2; j++){
            for (int k = 0; k < n; k++){
                cin >> arr[j][k];
            }
        }

        cout << max(dp(0,n), dp(1, n)) << "\n";
    }
}