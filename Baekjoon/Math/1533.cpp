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

int N, S, E, T;

const int MOD = 1000003;

vector<vector<ll>> operator*(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    vector<vector<ll>> ret(5 * N + 1, vector<ll>(5 * N + 1, 0));

    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            for (int k = 0; k < ret[i].size(); ++k) {
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<ll>> pow(vector<vector<ll>> &a, int t) {
    vector<vector<ll>> ret(5 * N + 1, vector<ll>(5 * N + 1, 0));
    for (int i = 0; i < 5*N+1; ++i) {
        ret[i][i] = 1;
    }

    do {
        if (t & 1) ret = ret * a;
        a = a * a;
    } while (t >>= 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> S >> E >> T;

    vector<vector<ll>> map(5 * N + 1, vector<ll>(5 * N + 1, 0));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            int dist = s[j] - '0';
            if (dist == 0) continue;

            int index = i * 5;
            for (int k = 0; k < dist - 1; ++k, ++index) {
                map[index][index + 1] = 1;
            }
            map[index][j * 5] = 1;
        }
    }

    map = pow(map, T);

    cout << map[(S - 1) * 5][(E - 1) * 5] << '\n';
}

