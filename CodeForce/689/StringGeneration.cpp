//
// Created by LeeChanYoung on 2020/12/11.
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
        int n, k;
        cin >> n >> k;

        vector<char> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back('a');
        }

        char cc = 'c';
        for (int i = 0; i < n - k; ++i) {
            ans.push_back(cc);

            if (--cc == 'a'-1){
                cc= 'c';
            }
        }

        for (char c : ans) {
            cout << c;
        }
        cout << "\n";
    }

}