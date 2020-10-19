//
// Created by CY on 2020-09-22.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n;
int arr[101];
ll memo[101][21];

ll dp(int index, int value){
    if (value < 0 || value > 20)
        return 0;

    if (index == n-2)
        return (value == arr[n-1]);

    ll &ret = memo[index][value];
    if (ret != -1)
        return ret;

    ret = dp(index+1, value + arr[index+1]) + dp(index+1, value - arr[index+1]);
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));
    cout << dp(0, arr[0]) << "\n";
}
