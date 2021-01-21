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
        int n;
        string b;

        cin >> n;
        cin >> b;

        vector<int> ans;
        char pre = 0;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] + 1 != pre) {
                b[i] += 1;
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }

            pre = b[i];
        }

        for (auto &i : ans)
            cout << i;

        cout << '\n';
    }
}