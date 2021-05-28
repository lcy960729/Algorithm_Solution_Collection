#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, W, L;
vector<int> a;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> W >> L;

    a.assign(N, 0);
    for (auto &i : a) {
        cin >> i;
    }

    queue<pii > q;
    int time = 0;
    int next = 0;
    int weight = 0;

    while (!(next == N && weight == 0)) {
        time++;

        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            pii cur = q.front();
            q.pop();

            if (++cur.second <= W)
                q.push(cur);
            else
                weight -= a[cur.first];
        }


        if (next < N && q.size() < W && weight + a[next] <= L) {
            q.push({next, 1});
            weight += a[next];

            next++;
        }
    }

    cout << time << '\n';
}