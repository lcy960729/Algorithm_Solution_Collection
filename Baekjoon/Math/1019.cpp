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

vector<int> ans(10, 0);
void calc(int temp, int p){
    while (temp > 0) {
        ans[temp % 10] += p;
        temp /= 10;
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    1 2 3 4 5 6 7 8 9 10
//    11 12 13 14 15 16 17 18 19 20
//    21

    int n;
    cin >> n;

    int s = 1, e = n, p = 1;
    while (s <= e) {
        while (e % 10 != 9 && s <= e) {
            calc(e, p);
            e--;
        }

        if (e < s) break;

        while (s % 10 != 0 && s <= e) {
            calc(s, p);
            s++;
        }

        s /= 10;
        e /= 10;

        for (int i = 0; i < 10; ++i) {
            ans[i] += (e - s + 1) * p;
        }

        p *= 10;
    }

    for (auto i : ans) {
        cout << i << " ";
    }

}