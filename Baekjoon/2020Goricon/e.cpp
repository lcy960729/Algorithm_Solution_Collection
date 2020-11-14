//
// Created by CY on 2020-10-14.
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

int N, L;

int box[200001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> box[i];
    }

    double sum = 0;
    for (int i = N - 2, j = 1; i >= 0; i--, j++) {
        sum += box[i+1];

        double center = sum;
        center /= j;

        double s = box[i] - L;
        double e = box[i] + L;

        if (center <= s || center >= e) {
            cout << "unstable";
            return 0;
        }
    }

    cout << "stable";
}