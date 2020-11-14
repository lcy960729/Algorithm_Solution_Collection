//
// Created by lcy96 on 2020-09-08.
//
//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define ll long long

using namespace std;

int memo[2001][2001];
int arr[2001];

int dp(int s, int e){
    if (s >= e){
        return 1;
    }

    int &result = memo[s][e];

    if (result != -1){
        return result;
    }

    if (arr[s] == arr[e]) {
        result = dp(s+1, e-1);
    }else{
        result = 0;
    }

    return result;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << dp(s,e) << "\n";
    }
}