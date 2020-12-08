//
// Created by LeeChanYoung on 2020/12/06.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int diff[367] = {};

    int mn = 1e9, mx = 0;
    for (int i = 0; i < N; ++i) {
        int s, e;
        cin >> s >> e;

        mn = min(mn, s);
        mx = max(mx, e);

        diff[s] += 1;
        diff[e+1] -= 1;
    }


    int diff_sum[367] = {};
    for (int i = 1; i <= 365; i++) {
        diff_sum[i] = diff_sum[i-1] + diff[i];
    }

    int ans = 0;

    int index = mn;
    while(index <= mx){
        if (diff_sum[index] != 0){
            int x = 0;
            int y = 0;

            while(diff_sum[index] != 0){
                x++;
                y = max(y, diff_sum[index]);
                index++;
            }
            ans += x*y;
        }else{
            index++;
        }
    }

    cout << ans;
}