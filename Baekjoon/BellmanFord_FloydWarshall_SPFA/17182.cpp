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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> dist(N, vector<int>(N, 1e9));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    vector<int> check(N);
    for (int i = 0; i < N; ++i) check[i] = i;

    int ans = 1e9;
    do {
        if (check[0] != K) continue;

        int sum = 0;
        for (int i = 0; i < check.size() - 1; ++i) {
            sum += dist[check[i]][check[i + 1]];
        }
        ans = min(ans, sum);
    } while (next_permutation(check.begin(), check.end()));

    cout << ans << '\n';
}