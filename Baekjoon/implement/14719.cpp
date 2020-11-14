//
// Created by CY on 2020-10-30.
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

int H, W;
bool arr[501][501] = {};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        int h;
        cin >> h;

        for (int j = 0; j < h; j++) {
            arr[j][i] = true;
        }
    }

    int ret = 0;
    for (int i = 0; i < H; i++) {
        int start = -1;

        for (int j = 0; j < W; j++) {
            if (arr[i][j]) {
                if (start != -1 && start < j) {
                    ret += j - start;
                }
                start = j+1;
            }
        }
    }
    cout << ret;
}
