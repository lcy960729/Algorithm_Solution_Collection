#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int memo[11][1028];
int n, m;
int board[11][11];

int dp(int cur, int preStudent) {
    if (cur == n) {
        return 0;
    }

    int &ret = memo[cur][preStudent];
    if (ret != -1) {
        return ret;
    }

    ret = dp(cur + 1, 0);

    for (int student = 1; student < (1 << m); student++) {

        bool isPossible = true;
        for (int j = 0; j < m && isPossible; j++) {
            if (student & (1 << j)) {
                if (j > 0 && (student & (1 << (j - 1))))
                    isPossible = false;

                if (j > 0 && (preStudent & (1 << (j - 1))))
                    isPossible = false;

                if (j < m - 1 && (preStudent & (1 << (j + 1))))
                    isPossible = false;

                if (board[cur][j] == 'x')
                    isPossible = false;
            }
        }

        if (!isPossible)
            continue;

        ret = max(ret, dp(cur + 1, student) + __builtin_popcount(student));
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

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++) {
                board[i][j] = str[j];
            }
        }

        memset(memo, -1, sizeof(memo));
        cout << dp(0, 0) << "\n";
    }
}