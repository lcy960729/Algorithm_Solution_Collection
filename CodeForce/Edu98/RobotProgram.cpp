//
// Created by LeeChanYoung on 2020/12/14.
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
        int x, y;
        cin >> x >> y;

        if (abs(x - y) < 2) {
            cout << x + y << "\n";
        }else{
            int mx = max(x, y);
            cout << 2*mx-1 << "\n";
        }
    }
}
