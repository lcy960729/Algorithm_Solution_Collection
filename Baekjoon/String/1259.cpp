//
// Created by LeeChanYoung on 2020/12/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

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

    while (true) {
        string s;
        cin >> s;

        if (s == "0") {
            break;
        }

        string rs = s;
        reverse(rs.begin(), rs.end());

        cout << (rs == s ? "yes" : "no") << "\n";
    }
}
