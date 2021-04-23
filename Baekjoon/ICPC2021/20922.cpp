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

    int n, k;
    cin >> n >> k;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> cnt(100001, 0);
    int l = 0, r = 1;
    cnt[arr[l]]++;
    cnt[arr[r]]++;

    int ans = 0;
    while (true) {
        if (r == arr.size()-1)
            break;

        if (cnt[arr[r]] <= k) {
            r++;
            cnt[arr[r]]++;
        }
        else {
            cnt[arr[l]]--;
            l++;
        }

        if (cnt[arr[r]] <= k && cnt[arr[l]] <= k)
            ans = max(ans, r-l+1);
    }
    cout << ans << '\n';
}