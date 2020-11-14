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

int N, M;
int board[1001][1001];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool visited[1001][1001] = {};
vector<pii > ans;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int curY = 0;
    int curX = 0;

    ans.push_back({0, 0});

    while (N - 2 > curY || M - 2 > curX) {
        if (N - 2 > curY)
            curY++;

        if (M - 2 > curX)
            curX++;

        ans.push_back({curY, curX});
    }

    curX++;
    ans.push_back({curY, curX});

    curY++;
    ans.push_back({curY, curX});

    cout << ((ans.size() / 2) + ans.size() % 2) * 4 << "\n";
    for (int i = 0; i < ans.size(); i += 2) {
        if (ans.size() - 1 == i) {
            cout << ans[i - 2].first << " " << ans[i - 2].second << "\n";
            cout << ans[i].first << " " << ans[i].second << "\n";
            cout << ans[i - 2].first << " " << ans[i - 2].second << "\n";
            cout << ans[i].first << " " << ans[i].second << "\n";
        } else {
            cout << ans[i].first << " " << ans[i].second << "\n";
            cout << ans[i + 1].first << " " << ans[i + 1].second << "\n";
            cout << ans[i].first << " " << ans[i].second << "\n";
            cout << ans[i + 1].first << " " << ans[i + 1].second << "\n";
        }
    }
}

