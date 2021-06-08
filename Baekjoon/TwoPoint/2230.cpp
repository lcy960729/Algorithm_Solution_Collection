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

int A[100001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A, A + N);

    int ans = 2e9+1;
    for (int r = 0, l = 1; r < N && l < N; ++r) {
        if (l < N && A[l] - A[r] < M) {
            l++;
            r--;
            continue;
        }
        ans = min(ans, A[l] - A[r]);
    }
    cout << ans << '\n';
}