//
// Created by CY on 2020-10-07.
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

int N;
vector<int> g[101];
bool visited[101][101];

vector<int> answer;

void dfs(int now, int end){
    for (int next : g[now]){
        if (visited[now][next])
            continue;

        if (next == end){
            answer.push_back(end);
            return;
        }

        visited[now][next] = true;
        dfs(next, end);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;

        g[i].push_back(num);
    }

    for (int i = 1; i <= N; i++){
        memset(visited, false, sizeof(visited));
        dfs(i,i);
    }
    cout << answer.size() << "\n";
    for (int ans : answer){
        cout << ans << "\n";
    }
}