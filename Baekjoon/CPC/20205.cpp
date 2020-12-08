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


int N, K;
int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    vector<vector<int>> picture(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> picture[i][j];
        }
    }

    vector<vector<int>> ans(N*K, vector<int>(N*K, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = i * K; k < i * K + K; ++k) {
                for (int l = j * K; l < j * K + K; ++l) {
                    ans[k][l] = picture[i][j];
                }
            }
        }
    }

    for (vector<int> a : ans){
        for (int i : a){
            cout << i << " ";
        }
        cout << "\n";
    }
}