//
// Created by LeeChanYoung on 2020/12/15.
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

        vector<int> a;
        vector<int> b;

        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;

            if (i < (n+1) / 2) {
                a.push_back(num);
            } else {
                b.push_back(num);
            }
        }

        reverse(b.begin(), b.end());

        int size = min(a.size(), b.size());
        for (int i = 0; i < size; ++i) {
            cout << a[i] << " ";
            cout << b[i] << " ";
        }

        if (n % 2) {
            cout << a[a.size()-1];
        }

        cout << "\n";
    }
}