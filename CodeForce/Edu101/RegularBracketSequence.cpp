//
// Created by LeeChanYoung on 2020/12/30.
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

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        if (s.length() % 2 == 0 &&
            s[0] != ')' &&
            s[s.length() - 1] != '(') {
            cout << "Yes" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}