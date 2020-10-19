//
// Created by CY on 2020-09-09.
//

//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;
pii app[101];
int memo[10001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++){
        cin >> app[i].first;
    }

    int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> app[i].second;
        sum += app[i].second;
    }

    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < N; i++){
        for (int j = sum; j >= app[i].second; j--){
            memo[j] = max(memo[j], memo[j-app[i].second] + app[i].first);
        }
    }

    for (int i = 0; i < sum ; i++){
        if (memo[i] >= M) {
            cout << i;
            break;
        }
    }
}

