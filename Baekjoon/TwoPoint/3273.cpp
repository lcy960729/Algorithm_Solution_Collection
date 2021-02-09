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

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    int x;
    cin >> x;

    sort(a.begin(), a.end());

    int ans = 0;
    int s = 0, e = a.size() - 1;
    while (s < e) {
        int sum = a[s] + a[e];
        if (sum < x) {
            s++;
        } else if (sum > x) {
            e--;
        } else {
            ans++;
            e--;
        }
    }

    cout << ans;
}