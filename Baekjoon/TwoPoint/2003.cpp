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

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (auto &i : a) {
        cin >> i;
    }

    ll ans = 0;
    ll sum = 0;
    for (int r = 0, l = 0; r < N; ++r) {
        sum += a[r];

        while (sum > M) {
            sum -= a[l];
            l++;
        }

        if (sum == M)
            ans++;
    }
    cout << ans << '\n';
}