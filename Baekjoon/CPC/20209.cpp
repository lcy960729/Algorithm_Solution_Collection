//
// Created by LeeChanYoung on 2020/12/06.
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

int N, K;

vector<int> btn[9];
set<string> visited;

bool check_ans(vector<int> &cube) {
    for (int i = 1; i < N; ++i) {
        if (cube[0] != cube[i]) {
            return false;
        }
    }
    return true;
}

void insert_visited(vector<int> &cube) {
    string str;
    for (int i : cube) {
        str.push_back(i + '0');
    }
    visited.insert(str);
}

bool check_visited(vector<int> &cube) {
    string str;
    for (int i : cube) {
        str.push_back(i + '0');
    }

    return (visited.find(str) != visited.end());
}

int bfs(vector<int> &cube) {
    queue<pair<vector<int>, int>> q;
    q.push({cube, 0});


    while (!q.empty()) {
        vector<int> cur = q.front().first;
        int count = q.front().second;
        q.pop();

        if (check_ans(cur)) {
            return count;
        }

        for (int i = 0; i < K; ++i) {
            vector<int> nextCube(N, 0);
            nextCube.assign(cur.begin(), cur.end());

            for (int cubeIndex : btn[i]) {
                nextCube[cubeIndex] = (cur[cubeIndex] + (i + 1)) % 5;
            }

            if (check_visited(nextCube)) {
                continue;
            }

            insert_visited(nextCube);
            q.push({nextCube, count + 1});
        }
    }

    return -1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    vector<int> cube(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> cube[i];
    }

    for (int i = 0; i < K; ++i) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; ++j) {
            int cubeIndex;
            cin >> cubeIndex;

            btn[i].push_back(cubeIndex - 1);
        }
    }

    cout << bfs(cube);
}