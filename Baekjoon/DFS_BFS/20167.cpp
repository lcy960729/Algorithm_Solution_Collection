//
// Created by LeeChanYoung on 2020/11/19.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, K;
ll arr[100005], ret[100005];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int p = 0;
    ll sum = 0, maxValue = 0;

    for (int i = 0; i < N; i++) {
        if (i != 0)
            maxValue = max(maxValue, ret[i-1]);

        while(p < N && sum < K){
            sum += arr[p++];
        }

        if (sum >= K){
            ret[p-1] = max(ret[p-1], maxValue + (sum - K));
        }else
            break;

        sum -= arr[i];
    }

    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, ret[i]);
    }
    cout << ans;
}