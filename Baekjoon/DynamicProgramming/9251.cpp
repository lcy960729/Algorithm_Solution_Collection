//
// Created by lcy96 on 2020-09-29.
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
int N, M;
int memo[1001][1001];
string a, b;

int dp(int pos1, int pos2) {
    if (pos1 == N || pos2 == M)
        return 0;

    int &ret = memo[pos1][pos2];
    if (ret != -1)
        return ret;

    if (a[pos1] == b[pos2])
        return 1 + dp(pos1 + 1, pos2 + 1);

    ret = max(dp(pos1 + 1, pos2), dp(pos1, pos2 + 1));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> a >> b;
    N = a.length();
    M = b.length();

    cout << dp(0, 0);
}