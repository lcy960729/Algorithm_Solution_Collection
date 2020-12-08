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
ll arr[100005];
ll ans = 0;

void dfs(int x, ll energy) {
    if (x > N) {
        ans = max(ans, energy);
        return;
    }

    ll sum = 0;
    for (int i = x; i < N; i++) {
        sum += arr[i];
        if (sum >= K) {
            dfs(i + 1, energy + sum - K);
            break;
        }
    }
    dfs(x + 1, energy);
}

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

    dfs(0, 0);
    cout << ans;
}