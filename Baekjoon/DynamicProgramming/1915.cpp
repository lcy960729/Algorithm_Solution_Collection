//
// Created by CY on 2020-09-22.
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

int n, m;
int box[1001][1001];
int memo[1001][1001];

int dp(int y, int x) {
    if (box[y][x] == 0) {
        return 0;
    }

    if (y < 0 || y >= n || x < 0 || x >= m) {
        return 0;
    }

    int &ret = memo[y][x];
    if (ret != -1) {
        return ret;
    }

    if (box[y][x] == 1) {
        ret = min({dp(y + 1, x), dp(y + 1, x + 1), dp(y, x + 1)}) + 1;
    }

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

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            box[i][j] = s[j] - '0';
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            result = max(result, dp(i, j));
        }
    }
    cout << result*result << "\n";
}
