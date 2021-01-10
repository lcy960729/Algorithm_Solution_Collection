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

int n, s;
int arr[100001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int sum = arr[0];
    int ans = 1e9;

    while (l <= r && r < n) {
        if (sum < s) {
            sum += arr[++r];
        } else {
            ans = min(ans, r - l + 1);

            if (l <= r){
                sum -= arr[l++];
            }
        }
    }

    cout << (ans == 1e9 ? 0 : ans) << "\n";
}