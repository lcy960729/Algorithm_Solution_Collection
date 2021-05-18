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

int N;

vector<vector<int>> g;

int dfs(int cur) {
    vector<int> time;
    for (auto &next : g[cur]) {
        time.push_back(dfs(next));
    }

    if (time.empty()) return 0;

    sort(time.rbegin(), time.rend());

    int ret = 0;
    for (int i = 0; i < time.size(); ++i) {
        ret = max(ret, time[i] + i + 1);
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


    cin >> N;

    g.assign(N + 1, vector<int>());
    for (int i = 0; i < N; ++i) {
        int boss;
        cin >> boss;

        if (boss == -1) continue;

        g[boss].push_back(i);
    }

    cout << dfs(0);
}