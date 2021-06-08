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

    int en, ed, a, c, x0;
    cin >> en >> ed >> a >> c >> x0;

    int L = a * x0 + c;
    cout << L << '\n';

    int an = a;
    int ad = 1;

    int rn = en * ad;
    int rd = an * ed;


    if (rn <= 0 || rd <= 0){
        cout << 0 << ' ' << 0;
    } else {
        cout << rn << ' ' << rd;
    }
}