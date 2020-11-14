//
// Created by CY on 2020-10-14.
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

int N;
int A[402][402], B[402][402];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;

            A[i][j] = A[i - 1][j - 1] + num;
            B[i][j] = B[i - 1][j + 1] + num;
        }
    }

    int ans = -1e9;

    for (int k = 2; k <= N; k++) {
        for (int i = k; i <= N; i++) {
            for (int j = k; j <= N; j++) {
                ans = max(ans, ((A[i][j] - A[i - k][j - k]) - (B[i][j - (k - 1)] - B[i - k][j - (k - 1) + k])));
            }
        }
    }

    cout << ans << "\n";
}