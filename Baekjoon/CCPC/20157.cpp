//
// Created by LeeChanYoung on 2020/11/28.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
int ans = 0;

map<double , int> mp[4];

void insert(int id, double m){
    if (mp[id].find(m) == mp[id].end()){
        mp[id][m] = 1;
    }else{
        mp[id][m]++;
    }

    ans = max(ans, mp[id][m]);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        double x, y, m;
        cin >> x >> y;

        m = (x==0) ? x : y/x;

        if (x < 0 && y < 0) {
            insert(0, m);
        }else if ( x <= 0 && y > 0){
            insert(1, m);
        }else if (x > 0 && y < 0){
            insert(2, m);
        }else if (x > 0 && y >= 0){
            insert(3, m);
        }
    }

    cout << ans;
}