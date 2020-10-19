//
// Created by CY on 2020-09-08.
//
//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>

#define pii pair<int, int>
#define ll long long

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ll l = 1, r = k;

    while (l+1 < r){
        ll m = (l+r)/2;

        long long cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += min(m/i, (ll)n);

        if (cnt < k)
            l = m;
        else
            r = m;
    }

    cout << r;
}
