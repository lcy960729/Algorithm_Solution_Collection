#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> res(n + 1, 1);
        n = unique(a.begin(), a.end()) -a.begin();
        a.resize(n);

        for (int i = 0; i < n; ++i) {
            res[a[i]] += 1;
        }

        res[a[0]] -= 1;
        res[a[n - 1]] -= 1;

        int ans = 1e9;

        for (int i = 0; i < n; ++i)
            ans = min(ans, res[a[i]]);

        cout << ans << "\n";
    }

}