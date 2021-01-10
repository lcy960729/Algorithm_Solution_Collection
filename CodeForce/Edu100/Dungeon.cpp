//
// Created by LeeChanYoung on 2020/12/17.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        int cnt = 0;
        while (a[0] + a[1] + a[2] != 0) {
            if (cnt % 7 == 6) {
                for (int &i : a) {
                    if (i > 0) {
                        i--;
                    }
                }
                cnt++;
            } else {
                int maxIndex = 0;
                for (int i = 1; i < 3; i++) {
                    if (a[maxIndex] < a[i]) {
                        maxIndex = i;
                    }
                }
                if (a[maxIndex] > 0){
                    a[maxIndex]--;
                    cnt++;
                }
            }
        }

        cout << (cnt % 7 == 0 ? "YES" : "NO") << "\n";
    }
}
