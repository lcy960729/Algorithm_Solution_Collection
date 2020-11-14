//
// Created by lcy96 on 2020-10-19.
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

int t, n;
ll memo[65][10];

ll dp(int num, int length){
    if (length == n){
        return 1;
    }

    ll &ret = memo[length][num];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = num; i <= 9; i++){
        ret += dp(i, length+1);
    }

    return ret;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> t;

    while(t--){
        cin >> n;

        memset(memo, -1, sizeof(memo));

        ll ans = 0;
        for (int i = 0; i <= 9; i++){
            ans += dp(i,1);
        }

        cout << ans << "\n";
    }
}