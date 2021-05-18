#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

static const int mod = 10007;
using namespace std;

int N, M, H;
vector<vector<int>> students;

int memo[51][1001] = {};

int dp(int cur, int size) {
    if (cur == N) {
        return size == H ? 1 : 0;
    }

    int &ret = memo[cur][size];
    if (ret != -1) return ret;

    ret = dp(cur + 1, size) % mod;
    for (int i = 0; i < students[cur].size(); ++i) {
        if (size + students[cur][i] > H) continue;

        ret += dp(cur + 1, size + students[cur][i]);
        ret %= mod;
    }

    return ret;
}

vector<string> split(string s, string separator) {
    vector<string> ret;

    int preIndex = 0;
    int currentIndex = s.find(separator, preIndex);
    while (currentIndex != string::npos) {
        string temp = s.substr(preIndex, currentIndex - preIndex);

        if (!temp.empty())
            ret.push_back(temp);

        preIndex = currentIndex + separator.size();

        currentIndex = s.find(separator, preIndex);
    }

    string temp = s.substr(preIndex, currentIndex - preIndex);

    if (!temp.empty())
        ret.push_back(temp);

    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N >> M >> H;

    students.assign(N, vector<int>());

    cin.ignore();
    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);
        vector<string> vs = split(s, " ");

        for (int j = 0; j < vs.size(); ++j) {
            students[i].push_back(stoi(vs[j]));
        }
    }

    memset(memo, -1, sizeof(memo));

    cout << dp(0, 0);
}