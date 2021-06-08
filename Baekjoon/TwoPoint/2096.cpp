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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int preMx[3] = {};
    int preMn[3] = {};
    int curMx[3] = {};
    int curMn[3] = {};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            int num;
            cin >> num;

            curMx[j] = curMn[j] = num;

            if (j == 0) {
                curMx[j] += max({preMx[0], preMx[1]});
                curMn[j] += min({preMn[0], preMn[1]});
            } else if (j == 1) {
                curMx[j] += max({preMx[0], preMx[1], preMx[2]});
                curMn[j] += min({preMn[0], preMn[1], preMn[2]});
            } else {
                curMx[j] += max({preMx[1], preMx[2]});
                curMn[j] += min({preMn[1], preMn[2]});
            }
        }
        memcpy(preMx, curMx, sizeof(preMx));
        memcpy(preMn, curMn, sizeof(preMn));
    }

    cout << *max_element(curMx, curMx + 3) << ' ' << *min_element(curMn, curMn + 3) << '\n';
}