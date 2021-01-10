//
// Created by LeeChanYoung on 2020/12/23.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
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

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pii> q;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;

            q.push({num, i});

            while (!q.empty() && q.front().first < num) {
                q.push(q.front());
                q.pop();
            }
        }

        int ans = 1;
        while(!q.empty() && q.front().second != m){
            ans++;
            q.pop();
        }

        cout << ans << "\n";
    }
}