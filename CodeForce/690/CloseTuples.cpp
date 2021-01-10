//
// Created by LeeChanYoung on 2020/12/16.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define ll long long
#define ull unsigned long long
using namespace std;

const int mod = 1e9 + 7;

ull memo[200011];

ull factorial(int n) {
    if (n <= 1)
        return 1;

    ull &ret = memo[n];
    if (ret != -1) {
        return ret;
    }

    ret = (n * factorial(n - 1)) % mod;
    return ret;
}


ull choose(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    ull ret = factorial(n);
    ret /= (factorial(r) * factorial(n - r)) % mod;
    ret %= mod;

    return ret;
}

ull solve(vector<int> &cnt, int n, int m, int k) {
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + cnt[i];
    }

    ull ans = 0;
    for (int i = -k; i < n; ++i) {
        int count = prefixSum[min(i + k + 1, n)] - prefixSum[max(i, 0)];
        ans += choose(count, m) % mod;
    }
    return ans % mod;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    memset(memo, -1, sizeof(memo));

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n, 0);
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
            cnt[a[i]]++;
        }

        cout << (solve(cnt, n, m, k) - solve(cnt, n, m, k - 1)) % mod << "\n";
    }
}