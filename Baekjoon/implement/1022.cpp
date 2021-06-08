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

int fun(int i, int j) {
    int n = max(abs(i), abs(j));

    int mx = (2 * n + 1) * (2 * n + 1);

    int diff = 2 * n;

    if (i == n) return mx - (n - j);
    mx -= diff;

    if (j == -n) return mx - (n - i);
    mx -= diff;

    if (i == -n) return mx - (n + j);
    mx -= diff;

    return mx - (n + i);
}

int g(int num);

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // (1,1) = 9, (1,0) = 8, (1, -1) = 7, (0,-1) = 6, (-1,-1) = 5
    // (-1,0) = 4, (-1,1) = 3, (0,1) = 2
    //
    // 2,2 max = 25 (2*n+1)^2

    int width = 0;
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            width = max(width, (int) to_string(fun(i, j)).size());
        }
    }

    cout.flags(ios::right);

    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            cout.width(width);
            cout << fun(i, j) << ' ';
        }
        cout << '\n';
    }
}