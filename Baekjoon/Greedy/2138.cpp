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

void switching(int index, vector<bool> &bulbs) {
    if (index > 0) {
        bulbs[index - 1] = !bulbs[index - 1];
    }

    bulbs[index] = !bulbs[index];

    if (index < bulbs.size() - 1) {
        bulbs[index + 1] = !bulbs[index + 1];
    }
}

int doSomeThing(vector<bool> &cur_bulbs, vector<bool> &goal_bulbs) {
    int cnt = 0;
    for (int i = 0; i < cur_bulbs.size(); ++i) {
        if (cur_bulbs[i] == goal_bulbs[i])
            continue;

        if (i + 1 == cur_bulbs.size()) {
            cnt = 1e9;
            break;
        }

        switching(i + 1, cur_bulbs);
        cnt++;
    }

    return cnt;
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> cur_bulbs(n, false);
    vector<bool> goal_bulbs(n, false);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        cur_bulbs[i] = s[i] - '0';
    }

    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        goal_bulbs[i] = s[i] - '0';
    }

    int ans = 1e9;
    for (int i = 0; i < 2; ++i) {
        vector<bool> temp(cur_bulbs);

        if (i == 0) {
            switching(0, temp);
        }

        ans = min(ans, doSomeThing(temp, goal_bulbs) + (i == 0 ? 1 : 0));
    }

    cout << (ans >= 1e9 ? -1 : ans) << '\n';
}