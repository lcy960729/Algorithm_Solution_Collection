//
// Created by LeeChanYoung on 2020/12/11.
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

bool check(int i, int j, int k, vector<vector<int>> &sum) {
    if (i + k - 1 > n || j + k - 1 > m || j - k < 0) {
        return false;
    }
    return sum[i + k - 1][j + k - 1] - sum[i + k - 1][j - k] == k * 2 - 1;
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

    while (t--) {

        cin >> n >> m;

        vector<vector<char>> matrix(n + 1, vector<char>(m + 1));
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> matrix[i][j];
                if (matrix[i][j] == '*') {
                    sum[i][j] = 1;
                }
                sum[i][j] += sum[i][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 1; k <= n; ++k) {
                    if (!check(i, j, k, sum))
                        break;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}