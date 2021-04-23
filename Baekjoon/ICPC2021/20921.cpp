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

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        ans.push_back(i);
    }

    int mx = n-1;
    while (k > 0) {
        int j = k >= mx ? mx : k;

        k -= j;

        auto begin = --ans.end();
        while (j--) --begin;

        reverse(begin, ans.end());
        reverse(++begin, ans.end());

        mx--;
    }

    for (auto i : ans) {
        cout << i << ' ';
    }

    // 12345
    // 51234 4개
    // 54123 3개
    // 54321

    // 1234
    // 1423
}