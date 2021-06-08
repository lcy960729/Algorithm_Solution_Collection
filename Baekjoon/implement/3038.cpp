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

int N;

void preOrder(int d, int cur) {

    if (d == 1) {
        cout << cur << ' ';
        return;
    }

    int start = (1 << N) - (1 << (N - d + 1));
    int end = 1 << (N - d);

    cout << end - cur + start + 1 << ' ';

    preOrder(d - 1, cur);
    preOrder(d - 1, cur + end);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<int> pre[16];
    vector<int> depth[16];

    pre[1].resize(2);
    pre[1][1] = 1;
    depth[1].resize(2);
    depth[1][1] = 1;

    for (int i = 2; i <= 15; ++i) {
        pre[i].resize((1 << i));
        depth[i].resize((1 << i));
        pre[i][1] = 1;
        depth[i][1] = 1;

        for (int j = 1; j <= (1 << (i - 1)) - 1; ++j) {
            depth[i][j + 1] = depth[i - 1][j] + 1;
            depth[i][j + (1 << (i - 1))] = depth[i - 1][j] + 1;

            if (depth[i - 1][j] + 1 != i) {
                pre[i][j + 1] = 2 * pre[i - 1][j] + 1;
                pre[i][j + (1 << (i - 1))] = 2 * pre[i - 1][j];
            } else {
                pre[i][j + 1] = 2 * pre[i - 1][j];
                pre[i][j + (1 << (i - 1))] = 2 * pre[i - 1][j] + 1;
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < depth[i].size(); ++j) {
            cout << depth[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < pre[i].size(); ++j) {
            cout << pre[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i = 1; i < (1 << N); ++i) {
        cout << pre[N][i] << ' ';
    }
}