//
// Created by LeeChanYoung on 2020/12/07.
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
        int n;
        cin >> n;

        vector<vector<char>> board(n, vector<char>(n));

        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;

            for (int j = 0; j < n; j++) {
                board[i][j] = str[j];
            }
        }


    }
}
