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

int n, w;

vector<pii > pathA;
vector<pii > pathB;

int memo[1001][1001];
int ans[1001][1001];

int getDist(vector<pii > &path, int incident, int a) {
    return abs(path[incident].first - path[a].first) + abs(path[incident].second - path[a].second);
}

int dp(int incidentA, int incidentB) {
    if (incidentA == w || incidentB == w) {
        return 0;
    }

    int &ret = memo[incidentA][incidentB];
    if (ret != -1) {
        return ret;
    }

    ret = 1e9;
    int nextIncident = max(incidentA, incidentB) + 1;

    int distA = getDist(pathA, nextIncident, incidentA);
    int distB = getDist(pathB, nextIncident, incidentB);

    int retA = dp(nextIncident, incidentB) + distA;
    int retB = dp(incidentA, nextIncident) + distB;

    ans[incidentA][incidentB] = (retA < retB ? 1 : 2);

    return ret = min(retA, retB);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> w;

    pathA.emplace_back(1, 1);
    pathB.emplace_back(n, n);

    for (int i = 0; i < w; ++i) {
        int x, y;
        cin >> x >> y;

        pathA.emplace_back(x, y);
        pathB.emplace_back(x, y);
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0) << "\n";
    for (int incidentA = 0, incidentB = 0; max(incidentA, incidentB) < w;) {
        cout << ans[incidentA][incidentB] << '\n';

        int nextIncident = max(incidentA, incidentB) + 1;

        if (ans[incidentA][incidentB] == 1)
            incidentA = nextIncident;
        else
            incidentB = nextIncident;
    }
}