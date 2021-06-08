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

    int N;
    cin >> N;

    if (N == 1){
        cout << 1 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }

    cout << N + N - 2 << '\n';

    for (int i = 1; i <= N; ++i) {
        cout << 1 << ' ' << i << '\n';
    }
    for (int i = 1; i <= N - 2; ++i) {
        cout << N << ' ' << 1 + i << '\n';
    }

}