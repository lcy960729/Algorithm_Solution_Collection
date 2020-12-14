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
        int n, k;
        cin >> n >> k;

        string a, b;
        cin >> a >> b;

        vector<int> have(27, 0);
        vector<int> need(27, 0);

        for (char c : a) {
            have[c - 'a']++;
        }
        for (char c : b) {
            need[c - 'a']++;
        }

        bool ans = false;
        for (int i = 0; i < 26; ++i) {
            if (have[i] < need[i] || (have[i] -= need[i]) % k)
                ans = true;

            have[i + 1] += have[i];
        }
        cout << (ans ? "No" : "Yes") << "\n";
    }
}