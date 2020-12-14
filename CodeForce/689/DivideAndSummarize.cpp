//
// Created by LeeChanYoung on 2020/12/12.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

void fun(int s, int e, vector<ll> &sum, vector<int> &a, set<ll> &ans) {
    ll sumTemp = sum[e - 1] - sum[s - 1];
    ans.insert(sumTemp);

    int mid = abs((a[s] + a[e - 1]) / 2);

    if (mid >= a[e - 1]) {
        return;
    }

    int midIndex = 0;
    for (int i = s; i < e; i++) {
        if (a[i] > mid) {
            midIndex = i;
            break;
        }
    }

    fun(s, midIndex, sum, a, ans);
    fun(midIndex, e, sum, a, ans);
}

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
        int n, q;
        cin >> n >> q;

        vector<int> a(n + 1);
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }

        set<ll> st;
        fun(1, n + 1, sum, a, st);

        for (int i = 0; i < q; ++i) {
            int s;
            cin >> s;

            cout << (st.find(s) != st.end() ? "YES\n" : "NO\n");
        }
    }
}
