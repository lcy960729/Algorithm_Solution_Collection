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

int board[1501][1501] = {};
int ans[1501] = {};
int temp[1501] = {};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];

            if (j == 0) {
                ans[i] = board[i][j];
            }
        }
    }

    for (int i = 1; i < N; ++i) {
        int r, l, cnt = 0;
        for (r = N - 1, l = N - 1; r - cnt >= 0; --r) {
            while (r >= 0 && l >= 0 && ans[r] < board[l][i]) {
                temp[r - cnt] = board[l][i];
                l--;
                cnt++;
            }
            if (r - cnt < 0) continue;
            temp[r - cnt] = ans[r];
        }

        memcpy(ans, temp, sizeof(temp));
    }

    cout << ans[0] << '\n';
}