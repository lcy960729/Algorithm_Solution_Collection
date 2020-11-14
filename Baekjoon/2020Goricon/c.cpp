//
// Created by CY on 2020-11-08.
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

int N, H, W;
char words[11][11*100];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> H >> W;

    for (int i = 0 ; i < H; i++){
        for (int j = 0; j < W*N; j++){
            cin >> words[i][j];
        }
    }

    char ans[102];
    fill(ans, ans+N, '?');

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W*N; j++){
            if (ans[j/W] == '?'){
                ans[j/W] = words[i][j];
            }
        }
    }

    ans[N] = '\0';
    cout << ans;
}