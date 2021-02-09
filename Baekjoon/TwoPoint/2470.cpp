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

    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());
    ll mn = LL_MAX;

    pii ans;
    int s = 0, e = a.size() - 1;
    while (s < e) {
        ll sum = a[s] + a[e];
        if (llabs(sum) < mn) {
            mn = llabs(sum);

            ans.first = s;
            ans.second = e;
        }

        if (sum < 0) {
            s++;
        } else {
            e--;
        }
    }

    cout << a[ans.first] << ' ' << a[ans.second];
}