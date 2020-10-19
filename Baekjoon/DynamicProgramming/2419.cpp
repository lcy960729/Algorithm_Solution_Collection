//
// Created by lcy96 on 2020-10-08.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n, m;
vector<int> location;
int memo[301][301];

int dp(int pre, int now, int cnt) {
    if (!cnt) {
        return 0;
    }

    int &ret = memo[pre][now];
    if (ret != -1)
        return ret;

    int l = min(pre, now), r = max(pre, now);

    ret = 1e9;

    if (r < n)
        ret = min(ret, dp(l, r + 1, cnt - 1) + cnt * (location[r + 1] - location[now]));

    if (l > 0)
        ret = min(ret, dp(r, l - 1, cnt - 1) + cnt * (location[now] - location[l - 1]));

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    location.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> location[i];
    }

    sort(location.begin(), location.end());
    int start = lower_bound(location.begin(), location.end(), 0) - location.begin();

    int ans = 0;
    for (int i = 1; i <= n; i++){
        memset(memo, -1, sizeof(memo));
        ans = max(ans, i * m - dp(start, start, i));
    }

    cout << ans;
}


