//
// Created by CY on 2020-10-06.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

string initialValue;
string resultValue = "123456780";

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

map<string, int> visited;

void bfs() {
    queue<string> q;
    q.push(initialValue);
    visited[initialValue] = 0;

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur == resultValue)
            return;

        int zeroIndex = cur.find('0');
        int y = zeroIndex / 3;
        int x = zeroIndex % 3;

        for (int i = 0; i < 4; i++) {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 3)
                continue;

            string next = cur;
            swap(next[zeroIndex], next[nextY * 3 + nextX]);

            if (visited.find(next) != visited.end())
                continue;

            visited[next] = visited[cur] + 1;
            q.push(next);
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

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;

            initialValue.push_back(num + '0');
        }
    }

    bfs();

    if (visited.find(resultValue) == visited.end()) {
        cout << -1;
    } else {
        cout << visited[resultValue];
    }
}