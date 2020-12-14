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

int n, m, A[100], B[100];
int memo[101][101];

int jlis(int indexA, int indexB){
    int &ret = memo[indexA + 1][indexB + 1];

    if (ret != -1) {
        return ret;
    }

    ret = 0;
    ll a = (indexA == -1 ? LONG_LONG_MIN : A[indexA]);
    ll b = (indexB == -1 ? LONG_LONG_MIN : B[indexB]);
    ll maxElement = max(a, b);

    for (int nextA = indexA + 1; nextA < n; ++nextA) {
        if (maxElement < A[nextA]) {
            ret = max(ret, jlis(nextA, indexB) + 1);
        }
    }

    for (int nextB = indexB + 1; nextB < m; ++nextB) {
        if (maxElement < B[nextB]) {
            ret = max(ret, jlis(indexA, nextB) + 1);
        }
    }
    return ret;
}

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
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }

        memset(memo, -1, sizeof(memo));

        cout << jlis(-1, -1) << '\n';
    }
}