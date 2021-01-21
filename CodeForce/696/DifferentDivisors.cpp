//
// Created by LeeChanYoung on 2021/01/21.
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

int number = 100001;
int a[100001];

void primeNumberSieve() {
    for (int i = 2; i <= number; ++i) {
        a[i] = i;
    }

    for (int i = 2; i <= number; ++i) {
        if (a[i] == 0) continue;

        for (int j = 2 * i; j <= number; j += i) {
            a[j] = 0;
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

    int t;
    cin >> t;

    primeNumberSieve();

    while (t--) {
        int d;
        cin >> d;

        int s[] = {1, 0, 0};
        for (int i = 0; i < 2; ++i) {
            for (int j = s[i] + d; j <= number; ++j) {
                if (a[j] == 0)
                    continue;

                s[i + 1] = j;
                j += d-1;
                break;
            }
        }

        cout << s[1] * s[2] << '\n';
    }
}