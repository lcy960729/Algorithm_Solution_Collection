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

int N;
vector<int> a;

int gcd(int a, int b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

int dc(int s, int e) {
    if (e - s == 1) {
        return a[s];
    }

    int frontSize = floor((e - s) / 2.0);
    int tempS = a[s];
    for (int i = 1; i < frontSize; ++i) {
        tempS = gcd(tempS, a[s + i]);
    }

    int backSize = ceil((e - s) / 2.0);
    int tempE = a[e - 1];
    for (int i = 1; i < backSize; ++i) {
        tempE = gcd(tempE, a[e - 1 - i]);
    }

    int ret = max(dc(s + frontSize, e) + tempS, dc(s, e - backSize) + tempE);

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    a.assign(N, 0);
    for (auto &i : a) {
        cin >> i;
    }

    cout << dc(0, N) << '\n';
}
