//
// Created by CY on 2020-09-23.
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

int t, N, memo[41]{0,1};

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 2; i <= 40; ++i){
        memo[i] = memo[i-1] + memo[i-2];
    }

    cin >> t;
    while(t--){
        cin >> N;

        if (N == 0)
            cout << "1 0\n";
        else
            cout << memo[N-1] << " " << memo[N] << "\n";
    }
}
