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

int H, W, X, Y;
vector<vector<int>> A, B;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W >> X >> Y;
    A.assign(H, vector<int>(W, 0));
    B.assign(H + X, vector<int>(W + Y, 0));

    for (auto &i : B) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i >= X && j >= Y) {
                A[i][j] = B[i][j] - A[i - X][j - Y];
            } else {
                A[i][j] = B[i][j];
            }

            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}