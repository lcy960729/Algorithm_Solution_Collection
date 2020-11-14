//
// Created by lcy96 on 2020-10-21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;

char map[51][51];
int height[51][51];

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool visited[51][51];

pii start;
int kCount;

int lo, hi;

int dfs(pii cur) {
    int ret = 0;
    //왜이러쥬?
    if (height[cur.first][cur.second] < lo || height[cur.first][cur.second] > hi)
        return ret;

    if (map[cur.first][cur.second] == 'K') {
        ret++;
    }

    for (int i = 0; i < 8; i++) {
        int ny = cur.first + dy[i];
        int nx = cur.second + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;

        if (visited[ny][nx])
            continue;

        visited[ny][nx] = true;

        ret += dfs({ny, nx});
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

    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            map[i][j]= str[j];

            if (map[i][j] == 'P') {
                start.first = i;
                start.second = j;
            } else if (map[i][j] == 'K') {
                kCount++;
            }
        }
    }

    set<int> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
            s.insert(height[i][j]);
        }
    }

    //투 포인터
    int ret = 1e9;
    auto l = s.begin();
    auto r = s.begin();

    while (r != s.end()) {
        while (l != s.end()) {
            memset(visited, false, sizeof(visited));
            lo = *l;
            hi = *r;

            visited[start.first][start.second] = true;

            if (dfs(start) != kCount)
                break;

            ret = min(ret, *r - *l);
            l++;
        }
        r++;
    }

    cout << ret << "\n";
}