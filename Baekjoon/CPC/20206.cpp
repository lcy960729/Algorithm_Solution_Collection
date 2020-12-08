//
// Created by LeeChanYoung on 2020/12/06.
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

    double A, B, C;
    cin >> A >> B >> C;

    double x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    double ret1 = (-(A * x1 + C)) / B;
    double ret2 = (-(A * x2 + C)) / B;
    double ret3 = (-(B * y1 + C)) / A;
    double ret4 = (-(B * y2 + C)) / A;

    bool check = true;

    if (y1 < ret1 && ret1 < y2) {
        check = false;
    } else if (y1 < ret2 && ret2 < y2) {
        check = false;
    } else if (x1 < ret3 && ret3 < x2) {
        check = false;
    } else if (x1 < ret4 && ret4 < x2) {
        check = false;
    }

    cout << (check ? "Lucky" : "Poor");
}