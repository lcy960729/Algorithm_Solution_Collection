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

    int x, n;
    cin >> x >> n;

    if ((n == 0 && x > 0) || (n == 1 && x < 0)) {
        cout << "INFINITE\n";
    } else if ((n == 0 && x <= 0) || (n == 1 && x >= 0)) {
        cout << "0\n";
    } else if (n % 2 && n != 1) {
        cout << "ERROR\n";
    } else {
        int cnt = 0;
        x -= n / 2;
        while (x > 0) {
            cnt++;
            x -= n / 2;
        }
        cout << cnt;
    }
}