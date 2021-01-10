//
// Created by LeeChanYoung on 2020/12/23.
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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<bool> primeNumber(n+1, true);
    primeNumber[1] = false;

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; i * j <= n; ++j) {
            primeNumber[i * j] = false;
        }
    }

    for (int i = m; i <= n; ++i) {
        if (primeNumber[i]) {
            cout << i << "\n";
        }
    }
}
