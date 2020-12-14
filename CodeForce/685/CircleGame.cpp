//
// Created by LeeChanYoung on 2020/12/14.
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
        int d, k;
        cin >> d >> k;

        int x = 0, y = 0;

        while (true) {
            if (x <= y && pow(x + k, 2) + pow(y, 2) <= pow(d, 2)) {
                x += k;
            } else if (x > y && pow(x, 2) + pow(y + k, 2) <= pow(d, 2)) {
                y += k;
            }else{
                break;
            }
        }

        if (x == y) {
            cout << "Utkarsh\n";
        }else{
            cout << "Ashish\n";
        }
    }
}
