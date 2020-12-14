//
// Created by LeeChanYoung on 2020/12/01.
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

int arr[501];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        int lx = 1;

        for (int i = 1; i <= n; ++i) {
            if (arr[i - 1] <= arr[i])
                continue;

            for (int j = lx; j <= i-1; j++) {
                if (arr[j] > x) {
                    swap(x, arr[j]);
                    ans++;
                }
            }

            if (i > 0 && arr[i - 1] > arr[i]) {
                ans = -1;
                break;
            }

            lx = i + 1;
        }
        cout << ans << "\n";
    }
}
