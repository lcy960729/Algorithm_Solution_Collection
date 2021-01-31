
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

void print(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> h(n + m+1, vector<ll>(n + m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> h[i][j];
            h[i][j] *= -1;
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            h[i][j] -= h[i - 1][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= 1; --j) {
            h[i][j] -= h[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!h[i][j]) continue;

            h[i][j + m] += h[i][j];
            h[i + m][j] += h[i][j];
            h[i + m][j + m] -= h[i][j];
        }
    }

    for (int i = 1; i <= m / 2; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "0 ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= n - m / 2; i++) {
        for (int j = 1; j <= m / 2; j++) {
            cout << "0 ";
        }

        for (int j = 1; j <= n - m / 2; j++) {
            cout << h[i][j] << ' ';
        }
        cout << '\n';
    }
}