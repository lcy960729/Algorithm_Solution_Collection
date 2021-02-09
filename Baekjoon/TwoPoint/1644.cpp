//
// Created by LeeChanYoung on 2021/02/01.
//

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

bool primeNum[4000001];
int p = 4000000;

void primeNumber() {
    memset(primeNum, true, sizeof(primeNum));
    primeNum[0] = false;
    primeNum[1] = false;

    for (int i = 2; i <= p; ++i) {
        for (int j = 2; i * j <= p; ++j) {
            primeNum[i * j] = false;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    primeNumber();

    vector<int> a;
    for (int i = 0; i <= p; ++i) {
        if (primeNum[i])
            a.push_back(i);
    }

    int ans = 0;
    int s = 0, e = 0;

    int sum = 0;
    while (s <= e && e < a.size()) {
        if (sum < n) {
            sum += a[e];
            e++;
        } else {
            if (sum == n) {
                ans++;
            }

            if (s <= e) {
                sum -= a[s++];
            }
        }
    }

    cout << ans;
}