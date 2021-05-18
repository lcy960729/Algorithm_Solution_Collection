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

int N, K;
vector<pii > cp;
int dist[501][501];
int memo[501][501];

int getDist(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// dp(N, k) N번 위치에서 k개의 체크포인트를 건너뛸때 감소되는 최소 거리

int dp(int n, int k) {
    if (n == N-1) {
        return 0;
    }

    int &ret = memo[n][k];
    if (ret != -1) {
        return ret;
    }

    ret = 1e9;
    for (int i = 0; i <= K - k; ++i) {
        // 넘어갈 횟수가 N보다 클 경우
        if (n + i + 1 > N)
            break;

        ret = min(ret, dp(n + i + 1, k + i) + dist[n][n + i + 1]);
    }

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    cp.assign(N, {0, 0});

    for (int i = 0; i < N; ++i) {
        cin >> cp[i].first >> cp[i].second;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            dist[i][j] = getDist(cp[i], cp[j]);
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0) << '\n';
}