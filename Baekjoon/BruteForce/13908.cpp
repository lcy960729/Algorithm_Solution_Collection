#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int M;
initializer_list<LNode> N;
vector<int> num;

int dfs(int cur, string s) {
    if (cur == N) {
        for (int i = 0; i < num.size(); ++i) {
            if (s.find(num[i] + '0') == string::npos)
                return 0;
        }

        return 1;
    }

    int ret = 0;
    for (int i = 0; i < 10; ++i) {
        ret += dfs(cur + 1, s + (char) (i + '0'));
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

    cin >> N >> M;
    num.assign(M, 0);

    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }

    cout << dfs(0, "") << '\n';
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int M;
initializer_list<LNode> N;
vector<int> num;
vector<int> check(10, 0);

int backTracking(int cur) {
    if (cur == N) {
        for (int i : num) {
            if (!check[i]) return 0;
        }
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < 10; ++i) {
        check[i]++;
        ret += backTracking(cur + 1);
        check[i]--;
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

    cin >> N >> M;
    num.assign(M, 0);

    for (int i = 0; i < M; ++i) {
        cin >> num[i];
    }

    cout << backTracking(0) << '\n';
}