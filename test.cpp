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

struct info {
    int c, m, p;
};

int N, M, K;
int memo[101][2001][501];

vector<info> infos;

int dp(int cur, int c, int p, int m) {
    if (cur == N + 1) {
        return m;
    }

    int &ret = memo[cur][c][p];
    if (ret != -1) {
        return ret;
    }

    ret = dp(cur + 1, c, p, m);
    ret = max(ret, dp(cur + 1, c + infos[cur].c, p + infos[cur].p, m + infos[cur].m) - infos[cur].m);

//    cout << cur << " : " << c << " : " << p << " = " << ret << '\n';

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;
    infos.assign(N, {});

    int sumP = 0;
    for (auto &i : infos) {
        cin >> i.c >> i.m >> i.p;
        sumP += i.p;
    }

    memset(memo, -1, sizeof(memo));

    dp(0, 0, 0, 0);

    int ans = 1e9;
    for (int i = 0; i < N; ++i) {
        for (int j = M-1; j < 2*M; ++j) {
            for (int k = 0; k < 501; ++k) {
                if (memo[i][j][k] >= K) {
                    ans = min(ans, k);
                }
            }
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << '\n';
}
