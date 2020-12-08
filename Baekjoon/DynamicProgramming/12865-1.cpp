//
// Created by LeeChanYoung on 2020/11/20.
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
vector<pii > product;
int memo[100001][101];

int dp(int index, int weight) {
    if (index == N) {
        return 0;
    }

    int &ret = memo[weight][index];
    if (ret != -1)
        return ret;

    ret = 0;
    if (weight + product[index].first <= K){
        ret = max(ret, dp(index + 1, weight + product[index].first) + product[index].second);
    }
    ret = max(ret, dp(index+1, weight));

    return ret;
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        product.push_back({w, v});
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0);
    cout << endl;
}
