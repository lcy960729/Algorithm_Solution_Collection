//
// Created by CY on 2020-10-15.
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

int H, W, K;
int board1[2501][2501];
int board2[5001][5001];
int ans1[2501][2501];
int ans2[5001][5001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << fixed;
    cout.precision(20);

    cin >> W >> H >> K;

    while (K--) {
        int op;
        cin >> op;
        if (op == 1) {
            int px, py, qx, qy;
            cin >> px >> py >> qx >> qy;

            board1[px][py]++;
            board1[px][qy + 1]--;
            board1[qx + 1][py]--;
            board1[qx + 1][qy + 1]++;

        } else {
            int tx, ty, r;
            cin >> tx >> ty >> r;

            int px = tx - ty - r + 2500;
            int py = tx - r + ty;
            int qx = tx - ty + r + 2500;
            int qy = tx + r + ty;

            board2[px][py]++;
            board2[px][qy + 1]--;
            board2[qx + 1][py]--;
            board2[qx + 1][qy + 1]++;
        }
    }

    ans1[0][0] = board1[0][0];
    for (int i = 1; i <= 2500; i++) {
        ans1[0][i] = ans1[0][i - 1] + board1[0][i];
        ans1[i][0] = ans1[i - 1][0] + board1[i][0];
    }
    for (int i = 1; i <= 2500; i++) {
        for (int j = 1; j < 2500; j++) {
            ans1[i][j] = ans1[i - 1][j] + ans1[i][j - 1] - ans1[i - 1][j - 1] + board1[i][j];
        }
    }

    ans2[0][0] = board2[0][0];
    for (int i = 1; i <= 5000; i++) {
        ans2[0][i] = ans2[0][i - 1] + board2[0][i];
        ans2[i][0] = ans2[i - 1][0] + board2[i][0];
    }
    for (int i = 1; i <= 5000; i++) {
        for (int j = 1; j <= 5000; j++) {
            ans2[i][j] = ans2[i - 1][j] + ans2[i][j - 1] - ans2[i - 1][j - 1] + board2[i][j];
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((ans1[j][i] + ans2[j - i + 2500][j + i]) % 2 == 0) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}