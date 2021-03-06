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

    string s;
    cin >> s;

    for (char c : s) {
        if (c == 'E' || c == 'I') {
            cout << (c == 'E' ? 'I' : 'E');
        } else if (c == 'S' || c == 'N') {
            cout << (c == 'S' ? 'N' : 'S');
        } else if (c == 'T' || c == 'F') {
            cout << (c == 'T' ? 'F' : 'T');
        } else if (c == 'J' || c == 'P') {
            cout << (c == 'J' ? 'P' : 'J');
        }
    }
}