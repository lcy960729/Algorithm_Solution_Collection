//
// Created by LeeChanYoung on 2020/12/16.
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = n; i >= 1; --i) {
            if (sum % i)
                continue;

            ll needSum = sum / i;
            ll curSum = 0;

            bool isOk = true;
            for (int j = 0; j < n; ++j) {
                curSum += a[j];
                if (curSum > needSum) {
                    isOk = false;
                    break;
                } else if (curSum == needSum) {
                    curSum = 0;
                }
            }

            if (isOk) {
                cout << n - i << '\n';
                break;
            }
        }
    }


}
