#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct query {
    int sTime;
    int eTime;
    bool isEnter;
    int id;

    bool operator<(const query &x) const {
        if (this->sTime == x.sTime) {
            if (this->eTime == x.eTime) {
                return !this->isEnter;
            }

            return this->eTime > x.eTime;
        }

        return this->sTime > x.sTime;
    }
};

int stringToTime(string s) {
    int ret = 0;
    ret += stoi(s.substr(0, 2)) * 60;
    ret += stoi(s.substr(2));

    return ret - 540;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t, p;
    cin >> n >> t >> p;

    vector<bool> isSeated(n + 1, false);
    vector<int> seatIndex(t + 1, 0);

    priority_queue<query> pq;

    for (int i = 1; i <= t; ++i) {
        string s, e;
        cin >> s >> e;

        int sTime = stringToTime(s);
        int eTime = stringToTime(e);

        pq.push({sTime, eTime, true, i});
        pq.push({eTime, sTime, false, i});
    }

    int ans = 720;
    while (!pq.empty()) {
        query cur = pq.top();
        pq.pop();

        if (!cur.isEnter) {
            if (seatIndex[cur.id] == p) {
                ans -= cur.sTime - cur.eTime;
            }

            isSeated[seatIndex[cur.id]] = false;
            seatIndex[cur.id] = 0;

            continue;
        }

        vector<int> seatTables(n + 1, 0);
        int mx = 1;
        for (int i = 1; i <= n; ++i) {
            if (isSeated[i]) continue;

            int l = i, r = i;
            bool isEmptyLeft = true, isEmptyRight = true;
            int lvalue = 0, rvalue = 0;

            while (--l >= 1) {
                lvalue = i - l;
                if (isSeated[l]) {
                    isEmptyLeft = false;
                    break;
                }
            }

            while (++r <= n) {
                rvalue = r - i;

                if (isSeated[r]) {
                    isEmptyRight = false;
                    break;
                }
            }

            if (isEmptyLeft && isEmptyRight) {
                seatTables[i] = max(lvalue, rvalue);
            } else if (!isEmptyLeft && isEmptyRight) {
                seatTables[i] = lvalue;
            } else if (isEmptyLeft && !isEmptyRight) {
                seatTables[i] = rvalue;
            } else {
                seatTables[i] = min(lvalue, rvalue);
            }

            if (seatTables[mx] < seatTables[i]) {
                mx = i;
            }
        }

        isSeated[mx] = true;
        seatIndex[cur.id] = mx;
    }

    cout << ans << '\n';
}