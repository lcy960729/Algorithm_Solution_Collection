//
// Created by LeeChanYoung on 2020/11/18.
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

int n, ans_min = 1e9, ans_max = 0;

int get_odd_cnt(int x) {
    int ret = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit % 2 == 1) ret++;
        x /= 10;
    }
    return ret;
}

void dfs(int x, int total_odd_cnt) {
    if (x <= 9) {
        ans_min = min(ans_min, total_odd_cnt);
        ans_max = max(ans_max, total_odd_cnt);
        return;
    }

    if (x <= 99) {
        int nx = (x / 10) + (x % 10);
        dfs(nx, get_odd_cnt(nx) + total_odd_cnt);
        return;
    }

    string s = to_string(x);
    for (int i = 0; i <= s.length() - 3; i++) {
        for (int j = i + 1; j <= s.length() - 2; j++) {
            string x1 = s.substr(0, i + 1);
            string x2 = s.substr(i + 1, j - i);
            string x3 = s.substr(j + 1);

            int nx = stoi(x1) + stoi(x2) + stoi(x3);
            dfs(nx, get_odd_cnt(nx) + total_odd_cnt);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dfs(n, get_odd_cnt(n));
    cout << ans_min << " " << ans_max << '\n';
}