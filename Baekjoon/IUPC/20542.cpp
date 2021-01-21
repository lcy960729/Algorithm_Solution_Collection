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
vector<vector<int>> memo;

bool isSame(char s1, char s2) {
    bool ijl = (s1 == 'i') && (s2 == 'i' || s2 == 'j' || s2 == 'l');
    bool vw = (s1 == 'v') && (s2 == 'v' || s2 == 'w');

    return ijl || vw || s1 == s2;
}

int dp(int id1, int id2, string &s, string &l) {
    if (id1 == s.length()) {
        return l.length() - id2;
    } else if (id2 == l.length()) {
        return s.length() - id1;
    }

    int &ret = memo[id1][id2];
    if (ret != -1)
        return ret;

    if (isSame(s[id1], l[id2])) {
        ret = dp(id1 + 1, id2 + 1, s, l);
    } else {
        ret = dp(id1 + 1, id2, s, l);
        ret = min(ret, dp(id1, id2 + 1, s, l));
        ret = min(ret, dp(id1 + 1, id2 + 1, s, l));

        ret++;
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

    int n, m;
    cin >> n >> m;

    memo.assign(n,vector<int>(m, -1));

    string s, l;
    cin >> s >> l;

    int ret = dp(0, 0, s, l);

    cout << ret;
}