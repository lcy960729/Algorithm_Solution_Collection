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
int cube[10];
vector<int> btn[10];

bool isSame() {
    for (int i = 2; i <= N; ++i) {
        if (cube[1] != cube[i]) {
            return false;
        }
    }
    return true;
}

int ans = 1e9;

void dfs(int idx, int cnt) {
    if (isSame())
        ans = min(ans, cnt);

    if (idx == K + 1) {
        return;
    }

    for (int i = 0; i <= 4; i++) {
        dfs(idx + 1, cnt + i);

        for (int cubeIndex : btn[idx]) {
            cube[cubeIndex] = (cube[cubeIndex] + idx) % 5;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> cube[i];
    }

    for (int i = 1; i <= K; i++) {
        int num;
        cin >> num;

        while (num--) {
            int cubeIndex;
            cin >> cubeIndex;

            btn[i].push_back(cubeIndex);
        }
    }

    dfs(1, 0);

    if (ans != 1e9) {
        cout << ans;
    } else {
        cout << -1;
    }
}