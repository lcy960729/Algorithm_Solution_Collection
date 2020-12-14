//
// Created by LeeChanYoung on 2020/12/14.
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

string S, W;
int memo[101][101];

bool matchMemoized(int w, int s) {
    int &ret = memo[w][s];

    if (ret != -1)
        return ret;

    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        return ret = matchMemoized(w + 1, s + 1);
    }

    if (w == W.size())
        return ret = (s == S.size());

    if (W[w] == '*') {
        if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1))) {
            return ret = 1;
        }
    }

    return ret = 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> W;

        int n;
        cin >> n;

        while (n--) {
            cin >> S;

            memset(memo, -1, sizeof(memo));

            if (matchMemoized(0, 0)) {
                cout << S << "\n";
            }
        }

    }
}
