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

int dx[] = {0, 1, 0, 1};
int dy[] = {0, 0, 1, 1};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll n, r, c;
    cin >> n >> r >> c;

    int size = pow(2, n);

    int ans = 0;

    while (n--) {
        size /= 2;
        int index = 0;

        if (c < size && r < size) {
            index = 0;
        } else if (c >= size && r < size) {
            index = 1;
        } else if (c < size && r >= size) {
            index = 2;
        } else if (c >= size && r >= size) {
            index = 3;
        }

        c %= size;
        r %= size;

        ans += pow(size, 2) * index;
    }
    cout << ans;
}