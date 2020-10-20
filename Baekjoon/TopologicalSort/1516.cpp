//
// Created by CY on 2020-09-18.
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> building(501);
    int cost[501];
    int indegree[501] = {};
    int result[501] = {};

    queue<int> q;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];

        while (true) {
            int needBuilding;
            cin >> needBuilding;

            if (needBuilding == -1)
                break;

            building[needBuilding].push_back(i);
            indegree[i]++;
        }

        if (indegree[i] == 0) {
            result[i] = cost[i];
            q.push(i);
        }
    }

    for (int i = 0; i < n; i++) {
        int cur = q.front();
        q.pop();

        for (int next : building[cur]) {
            result[next] = max(result[next], result[cur] + cost[next]);
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << "\n";
}
