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

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        auto isBeautiful = [&](int l, int r, int preNumIndex) -> bool {
            if (l == r || s[r] == '?')
                return true;

            if (preNumIndex != -1) {
                bool check1 = ((r - preNumIndex) % 2) && s[r] == s[preNumIndex];
                bool check2 = !((r - preNumIndex) % 2) && s[r] != s[preNumIndex];

                if (check1 || check2)
                    return false;
            }

            return s[r] != s[r - 1];
        };

        int preNumIndex = -1;
        ll ans = 0;
        for (int r = 0, l = 0; r < s.size(); ++r) {
            if (r > 0 && s[r] == '?' && s[r - 1] != '?')
                preNumIndex = r - 1;

            while (!isBeautiful(l, r, preNumIndex)) {
                l++;

                if (preNumIndex < l)
                    preNumIndex = -1;
            }
            ans += r - l + 1;
        }

        cout << ans << '\n';
    }
}

