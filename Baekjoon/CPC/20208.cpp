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

int N, M, H;
int map[10][10];
pii home;
vector<pii > mintChocoMilk;
bool visited[11] = {};
int ans = 0;

void dfs(int cur, int hp, int count) {
    if (cur == mintChocoMilk.size() - 1 && count != 0) {
        ans = max(ans, count-1);
        return;
    }

    for (int i = 0; i < mintChocoMilk.size(); i++) {
        if (visited[i])
            continue;

        int cost = abs(mintChocoMilk[cur].first - mintChocoMilk[i].first);
        cost += abs(mintChocoMilk[cur].second - mintChocoMilk[i].second);

        if (hp >= cost) {
            visited[i] = true;
            dfs(i, hp - cost + H, count + 1);
            visited[i] = false;
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

    cin >> N >> M >> H;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                home = {i, j};
            } else if (map[i][j] == 2) {
                mintChocoMilk.push_back({i, j});
            }
        }
    }

    mintChocoMilk.push_back(home);
    dfs(mintChocoMilk.size() - 1, M, 0);
    cout << ans;
}