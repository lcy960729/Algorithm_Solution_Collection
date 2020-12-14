//
// Created by LeeChanYoung on 2020/12/14.
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

int dfs(int num){
    if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    }

    int ret;
    if (num % 2 == 1) {
        ret = dfs(num - 1) + 1;
    }else{
        ret = dfs(num / (num / 2)) + 1;
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << dfs(n) << "\n";
    }
}