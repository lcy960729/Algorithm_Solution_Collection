#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18


//TODO 다시 풀어보기
using namespace std;

vector<vector<ll>> H;
vector<vector<ll>> pSum;
vector<vector<ll>> ans;

ll gridSum(int y1, int x1, int y2, int x2) {
    ll ret = pSum[y2][x2];
    if (y1 > 0) ret -= pSum[y1 - 1][x2];
    if (x1 > 0) ret -= pSum[y2][x1 - 1];
    if (y1 > 0 && x1 > 0) ret += pSum[y1 - 1][x1 - 1];
    return ret;
}

void printArray(vector<vector<ll>> &a){
    for (auto &i : a) {
        for (auto &j : i) cout << j << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void checkBomb(int n, int y, int x, int r) {
    if (y + r >= n || x + r >= n)
        return;

    ans[y + r][x + r] = abs(H[y][x])
                        - abs(gridSum(y - r + 1, x - r + 1, y + r + 1, x + r + 1) - pSum[y + r][x + r]);

    pSum[y + r + 1][x + r + 1] =
            ans[y + r][x + r]
            + pSum[y + r + 1][x + r]
            + pSum[y + r][x + r + 1]
            - pSum[y + r][x + r];

    pSum[y + r + 1][x + r + 2] += pSum[y + r + 1][x + r + 1];
    pSum[y + r + 2][x + r + 1] += pSum[y + r + 1][x + r + 1];

    printArray(ans);
    printArray(pSum);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    H.assign(N, vector<ll>(N, 0));
    pSum.assign(N + 2, vector<ll>(N + 2));
    ans.assign(N, vector<ll>(N, 0));

    for (vector<ll> &vi : H) {
        for (auto &i : vi) {
            cin >> i;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            checkBomb(N, i, j, M / 2);
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

