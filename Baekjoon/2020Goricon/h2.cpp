//
// Created by LeeChanYoung on 2020/11/15.
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

int N, M;
vector<int> g[200001];
bool visited[200001];
int recipe[200001];
int indegree[200001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            g[x].push_back(i);
        }

        cin >> recipe[i];
        indegree[i] += k;
    }

    int l;
    cin >> l;

    queue<int> q;
    for (int i = 0; i < l; i++) {
        int y;
        cin >> y;
        q.push(y);
        visited[y] = true;
    }

    vector<int> ans;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int next : g[cur]){
            if (visited[recipe[next]])
                continue;

            if (--indegree[next])
                continue;

            visited[recipe[next]]= true;
            q.push(recipe[next]);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
}