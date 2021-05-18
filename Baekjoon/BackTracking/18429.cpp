#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, K;
int kit[51] , visited[51], order[51];

int bt(int cnt) {
    if (cnt == N) {
        int mx = 500;
        for (int i = 0; i < N; ++i) {
            mx += kit[order[i]] - K;

            if (mx < 500) break;
        }

        return mx < 500 ? 0 : 1;
    }

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (visited[i]) continue;

        order[cnt] = i;
        visited[i] = true;
        ret += bt(cnt + 1);
        visited[i] = false;
    }

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
        cin >> kit[i];
    }

    cout << bt(0) << '\n';
}