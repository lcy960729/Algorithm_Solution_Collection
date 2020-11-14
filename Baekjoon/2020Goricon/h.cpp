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
vector<int> cnt[200001];
vector<pii > recipe[200001];
bool visited[200001];

int numOfRecipe[200001] = {};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int size;
        cin >> size;

        vector<int> xArray(size);
        for (int j = 0; j < size; j++) {
            cin >> xArray[j];
        }

        int r;
        cin >> r;

        for (int x : xArray) {
            recipe[x].push_back({r, cnt[r].size()});
        }
        cnt[r].push_back(xArray.size());
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
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for (pii next : recipe[cur]) {
            if (visited[next.first])
                continue;

            if (--cnt[next.first][next.second])
                continue;

            visited[next.first] = true;
            q.push(next.first);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
}