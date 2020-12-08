//
// Created by LeeChanYoung on 2020/11/30.
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

ll oddSum[100002];
ll evenSum[100002];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int lastNum;
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;

        evenSum[i] = evenSum[i - 1];
        oddSum[i] = oddSum[i - 1];

        if (i % 2 == 0) {
            evenSum[i] += num;
        } else {
            oddSum[i] += num;
        }

        if (i == N)
            lastNum = num;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, oddSum[i - 1] + (evenSum[N - 1] - evenSum[i-1]) + (i % 2 == 0 ? 0 : lastNum));
    }

    cout << ans;
}