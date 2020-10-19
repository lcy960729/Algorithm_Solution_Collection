//
// Created by lcy96 on 2020-09-22.
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
int memo[1001];

int dp(int length){
    if (length == 1) {
        return 1;
    }else if (length == 2) {
        return 2;
    }

    int &ret = memo[length];
    if (ret != -1)
        return ret;

    ret = (dp(length-1) % 10007 + dp(length-2) % 10007) % 10007;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> n;

    cout << dp(n) << "\n";
}
