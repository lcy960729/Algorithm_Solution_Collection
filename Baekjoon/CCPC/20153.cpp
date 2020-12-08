//
// Created by LeeChanYoung on 2020/11/22.
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

int N;
int A[2222223];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        temp ^= A[i];
    }

    int ans = temp;
    for (int i = 0; i < N; i++) {
        ans = max(ans, temp ^ A[i]);
    }

    cout << ans;
    cout << ans;
}