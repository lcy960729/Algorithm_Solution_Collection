//
// Created by lcy96 on 2020-10-06.
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

int N, M;
int pSum[100001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        pSum[i+1] = pSum[i] + num;
    }

    for (int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        cout << pSum[e]-pSum[s-1] << "\n";
    }
}