//
// Created by LeeChanYoung on 2020/12/22.
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

    int n;
    cin >> n;

    int ans = 0;
    int cur = 666;

    while (true) {
        if (ans == n) {
            cout << cur-1 << "\n";
            break;
        }

        if (to_string(cur).find("666") != string::npos) {
            ans++;
        }

        cur++;
    }
}
