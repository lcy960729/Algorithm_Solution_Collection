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


    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;

        if (c == 'J' || c == 'A' || c == 'V') continue;
        s += c;
    }

    cout << (s.empty() ? "nojava" : s);
}