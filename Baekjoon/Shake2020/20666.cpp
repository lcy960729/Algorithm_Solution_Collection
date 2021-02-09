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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> c(n);
    for (auto &i : c) {
        cin >> i;
    }

    int p;
    cin >> p;

    vector<vector<pii>> g(n, vector<pii>());
    for (int i = 0; i < p; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;

        c[b] += t;
        g[a].push_back({b, t});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push({c[i], i});
    }

    ll ans = 0;
    vector<bool> fin(n, false);
    while(!pq.empty()){
        pair<ll, int> cur = pq.top();
        pq.pop();

        if (fin[cur.second])
            continue;

        ans = max(ans, cur.first);
        if (!--m){
            cout << ans << '\n';
            break;
        }

        for (pii next : g[cur.second]){
            c[next.first] -= next.second;

            pq.push({c[next.first], next.first});
        }

        fin[cur.second] = true;
    }
}