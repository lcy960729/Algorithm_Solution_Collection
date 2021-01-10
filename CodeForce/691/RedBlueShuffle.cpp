//
// Created by LeeChanYoung on 2020/12/19.
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

        string red, blue;

        cin >> red;
        cin >> blue;

        int r = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (red[i] > blue[i])
                r++;
            else if (red[i] < blue[i]) {
                b++;
            }
        }

        if (r > b) {
            cout << "RED" << "\n";
        } else if (r < b) {
            cout << "BLUE" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }
}