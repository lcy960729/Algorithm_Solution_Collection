#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

void dfs(int cur, vector<set<int>> &g, vector<bool> &visited){
    for (auto next : g[cur]) {
        if (visited[next]) continue;

        visited[next] = true;
        dfs(next, g, visited);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int numOfBlockUsers;
    cin >> numOfBlockUsers;

    vector<set<int>> g(n + 1, set<int>());
    set<int> blockUserSet;

    for (int i = 0; i < numOfBlockUsers; ++i) {
        int blockUser;
        cin >> blockUser;

        blockUserSet.insert(blockUser);
    }

    vector<vector<int>> party(m, vector<int>());

    int ans = 0;
    for (auto &people : party) {
        int numOfPeople;
        cin >> numOfPeople;

        people.assign(numOfPeople, 0);
        for (auto &person : people) {
            cin >> person;
        }

        for (int i = 0; i < people.size(); ++i) {
            for (int j = i + 1; j < people.size(); ++j) {
                g[people[i]].insert(people[j]);
                g[people[j]].insert(people[i]);
            }
        }
    }

    vector<bool> visited(n, false);
    for (auto &i : blockUserSet) {
        visited[i] = true;
        dfs(i, g, visited);
    }

    for (auto &people : party) {
        bool check = true;

        for (auto &person : people) {
            if (visited[person]) {
                check = false;
                break;
            }
        }

        if (check) ans++;
    }

    cout << ans << '\n';
}