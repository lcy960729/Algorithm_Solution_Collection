//
// Created by CY on 2020-10-14.
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

int N;

int diff[10001];
int diff_sum[10001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    while (N--) {
        int s, e;
        cin >> s >> e;

        diff[s] += 1;
        diff[e] -= 1;
    }

    int ans = 0;

    for (int i = 1; i <= 10000; i++) {
        diff_sum[i] = diff_sum[i - 1] + diff[i];

        if (diff_sum[i])
            ans++;
    }

    cout << ans << "\n";
}