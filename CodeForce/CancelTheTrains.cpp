//
// Created by LeeChanYoung on 2020/12/06.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int t;


int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        set<int> train;

        for (int i = 0; i < n+m; ++i) {
            int x;
            cin >> x;

            train.insert(x);
        }

        cout << n + m - train.size() << "\n";
    }
}