//
// Created by LeeChanYoung on 2020/12/18.
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

const int mod = 1000000;
const int P = (mod / 10) * 15;

int fibo[P] = {0, 1};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;

    for (int i = 2; i < P; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= mod;
    }

    cout << fibo[n % P] << "\n";
}
