#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, K;
int memo[101][1025];
vector<bool> startStatus, endStatus;

int dp(int id, int status) {
    if (id == N - K + 2) {
        for (int i = 0; i < K - 1; i++) {
            bool temp = (status & (1 << i)) ? !startStatus[i + id] : startStatus[i+id];

            if (temp != endStatus[i + id])
                return 1e9;
        }
        return 0;
    }

    int &ret = memo[id][status];
    if (ret != -1) {
        return ret;
    }

    ret = 1e9;
    if (startStatus[id] ^ endStatus[id] ^ (status & (1 << 0))) {
        for (int i = 0; i < K - 1; ++i) {
            int nextStatus = 0;
            for (int j = 0; j < K - 1; ++j) {
                if (i != j)
                    nextStatus |= (1 << j);
            }
            ret = min(ret, dp(id + 1, (status >> 1) ^ nextStatus));
        }
        ret++;
    } else {
        ret = dp(id + 1, status >> 1);
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

    for (int i = 0; i < N; ++i) {
        bool c;
        cin >> c;

        startStatus.push_back(c);
    }

    for (int i = 0; i < N; ++i) {
        bool c;
        cin >> c;

        endStatus.push_back(c);
    }

    memset(memo, -1, sizeof(memo));

    int ans = dp(0, 0);
    cout << (ans >= 1e9 ? -1 : ans);
}