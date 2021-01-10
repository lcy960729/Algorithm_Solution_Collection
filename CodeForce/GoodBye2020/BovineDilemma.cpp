//
// Created by LeeChanYoung on 2020/12/30.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

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

        vector<int> x(n);
        for (auto &i : x) {
            cin >> i;
        }

        if (n <= 2){
            cout << n-1 << "\n";
            continue;
        }

        vector<bool>check(n, true);
        for (int i = 0; i < n - 2; ++i) {
            check[i] = false;
        }

        set<double> set1;
        do{
            int v = 0;
            for (int i = 0; i < n; ++i) {
                if (check[i]){
                    if (v == 0)
                        v = x[i];
                    else{
                        v = abs(v-x[i]);
                    }
                }
            }
            set1.insert((1*v)/2.0);
        }while(next_permutation(check.begin(), check.end()));
        cout << set1.size() << "\n";
    }
}