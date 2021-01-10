//
// Created by LeeChanYoung on 2020/12/19.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    ll ans;
    if (n % 2 == 0) {
        ans = (n / 2 + 1) * (n / 2 + 1);
    } else {
        ans = (n / 2 + 1) * (n / 2 + 2) * 2;
    }

    cout << ans;
}