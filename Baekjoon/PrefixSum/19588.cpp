//
// Created by LeeChanYoung on 2021/02/01.
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

    int n, m;
    cin >> n >> m;

    vector<pii > s(n+1);
    vector<ll> xor1(n + 1, 0);
    vector<ll> xor2(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> s[i].first >> s[i].second;
    }

    sort(s.rbegin(), --s.rend());

    for (int i = 1; i <= n; ++i) {
        xor1[i] = xor1[i - 1] ^ s[i].second;
    }

    for (int i = m; i <= n; ++i) {
        xor2[i] = xor2[i - m] + (xor1[i] ^ xor1[i - m]);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;

        cout << xor2[b + a * m] - xor2[b] << '\n';
    }
}
