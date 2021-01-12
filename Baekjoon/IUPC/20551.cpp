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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for (auto &i : a) {
        cin >> i;
    }

    sort(a.begin(), a.end());

    while (M--) {
        int d;
        cin >> d;

        int l = -1, r = N-1, m;
        while (l + 1 < r) {
            m = (l + r) / 2;
            if (a[m] >= d) {
                r = m;
            } else {
                l = m;
            }
        }
        cout <<  (d == a[r] ? r : -1) << "\n";
    }
}