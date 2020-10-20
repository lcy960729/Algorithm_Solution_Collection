//
// Created by CY on 2020-10-15.
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

int N, M;

vector<pii> node(200002);

vector<int> yIndex;
map<int, int> mp;
int newYIndex = 1;

long long diff[200002];
long long diff_sum[200002];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        node[i] = {x, y};
        yIndex.push_back(y);
    }

    sort(yIndex.begin(), yIndex.end());

    for (int i : yIndex) {
       if (mp.find(i) == mp.end())
           mp[i] = newYIndex++;
    }

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        int s = mp[node[u].second];
        int e = mp[node[v].second];

        if (s > e) swap(s, e);

        diff[s] += c;
        diff[e + 1] -= c;
    }

    long long ans = 0;
    for (int i = 1; i < newYIndex; i++) {
        diff_sum[i] = diff_sum[i - 1] + diff[i];
        ans = max(ans, diff_sum[i]); 
    }

    cout << ans << "\n";
}
