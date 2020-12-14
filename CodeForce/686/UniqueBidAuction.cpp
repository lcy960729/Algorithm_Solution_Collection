//
// Created by LeeChanYoung on 2020/12/13.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

bool cmp(const pii &p1, const pii &p2){
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
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
        int n;
        cin >> n;

        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            mp[a].push_back(i);
        }

        int ans = 1e9;
        int value = 1e9;
        for (auto a : mp){
            if (a.second.size() != 1)
                continue;

            if (value > a.first){
                value = a.first;
                ans = a.second[0];
            }
        }

        if (ans == 1e9) {
            cout << -1 << "\n";
        } else {
            cout << ans+1 << "\n";
        }
    }
}