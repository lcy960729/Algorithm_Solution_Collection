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

int getDist(pii p1, pii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pii > cp(N);
    int total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> cp[i].first >> cp[i].second;
        if (i > 0) {
            total += getDist(cp[i - 1], cp[i]);
        }
    }

    int ans = 1e9;
    for (int i = 1; i < N - 1; ++i) {
        int aToc = getDist(cp[i - 1], cp[i + 1]);
        int aTob = getDist(cp[i - 1], cp[i]);
        int bToc = getDist(cp[i], cp[i + 1]);

        ans = min(ans, total - (aTob + bToc) + aToc);
    }

    cout << ans << '\n';
}