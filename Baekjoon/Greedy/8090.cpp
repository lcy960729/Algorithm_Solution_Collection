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

struct Node {
    int from, to, cnt;

    bool operator<(const Node &n1) const {
        if (this->from == n1.from) {
            if (this->to == n1.to) {
                return this->cnt > n1.cnt;
            }

            return this->to < n1.to;
        }

        return this->from < n1.from;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    cin >> N >> C;

    int M;
    cin >> M;

    vector<vector<Node>> list(N + 1, vector<Node>());
    for (int i = 0; i < M; ++i) {
        int to, from, cnt;
        cin >> to >> from >> cnt;

        list[to].push_back({to, from, cnt});
    }

    for (int i = 0; i < N; ++i) {
        sort(list[i].begin(), list[i].end());
    }

    vector<int> boxes(N + 1, 0);

    int now = 0;
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        ans += boxes[i];
        now -= boxes[i];
        boxes[i] = 0;

        for (int j = 0; j < list[i].size(); ++j) {
            auto &box = list[i][j];

            int need = C > box.cnt ? box.cnt : C;

            if (need > C - now) {
                // 부족한 량 = 필요한 량 + 현재 량 - 최대량
                int insufficient = need + now - C;

                for (int k = N; k > box.to; --k) {
                    if (insufficient <= boxes[k]) {
                        boxes[k] -= insufficient;
                        now -= insufficient;
                        insufficient = 0;
                        break;
                    } else {
                        now -= boxes[k];
                        insufficient -= boxes[k];
                        boxes[k] = 0;
                    }
                }

                // 최대 넣을 수 있는 량이 필요량 - 부족한량
                need = C - now > need - insufficient ? need - insufficient : C - now;
            }

            now += need;
            boxes[box.to] += need;
        }
    }
    cout << ans << '\n';
}