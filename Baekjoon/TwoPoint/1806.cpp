//
// Created by LeeChanYoung on 2020/12/30.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

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

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    int l = 0, r = 0;
    int sum = a[0];
    int ans = 1e9;

    while (l <= r && r < n) {
        if (sum < s) {
            sum += a[r];
            r++;
        } else {
            ans = min(ans, r - l + 1);

            if (l <= r){
                sum -= a[l++];
            }
        }
    }

    cout << (ans == 1e9 ? 0 : ans) << "\n";
}