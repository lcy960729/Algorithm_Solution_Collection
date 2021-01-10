//
// Created by LeeChanYoung on 2020/12/15.
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
        int n;
        cin >> n;

        string s;
        cin >> s;

        if ((s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') ||
            (s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n - 1] == '0') ||
            (s[0] == '2' && s[1] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
            (s[0] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0') ||
            (s[n - 4] == '2' && s[n - 3] == '0' && s[n - 2] == '2' && s[n - 1] == '0')) {

            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}