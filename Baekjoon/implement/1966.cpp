//
// Created by CY on 2020-09-26.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int t;
int N, M;
queue<int> q;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while(t--){
        cin >> N >> M;

        for (int i = 0; i < N; ++i){
            int order;
            cin >> order;
            q.push(order);
        }

        while(true){
            int cur = q.front();

        }


    }

}