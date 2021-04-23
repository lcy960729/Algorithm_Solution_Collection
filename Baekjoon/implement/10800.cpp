#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Node {
    int size, color, id;

    bool operator<(const Node &st1) const {
        if (this->size == st1.size) {
            return this->color < st1.color;
        }
        return this->size < st1.size;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Node> balls(N);
    for (int i = 0; i < N; ++i) {
        cin >> balls[i].color >> balls[i].size;

        balls[i].id = i;
        balls[i].color--;
    }

    sort(balls.begin(), balls.end());

    ll totalSum = 0;
    vector<ll> colorSum(N, 0);
    map<int, ll> prefixSum;
    vector<map<int, ll>> prefixSumOfColor(N, map<int, ll>());

    vector<ll> ans(N);

    for (auto ball : balls) {
        if (prefixSum.find(ball.size) == prefixSum.end()) {
            // 이전까지 합해진 값을 넣어줌, 단 한번만
            prefixSum[ball.size] = totalSum;
        }
        // 먹을 수 있는 값을 계속 합쳐줌
        totalSum += ball.size;

        // 칼러에 맞는 값을 넣어주는거임
        if (prefixSumOfColor[ball.color].find(ball.size) == prefixSumOfColor[ball.color].end()) {
            // 똑같이 해당 칼러로 이전까지 합해진 값을 넣어줌, 단 한번만
            prefixSumOfColor[ball.color][ball.size] = colorSum[ball.color];
        }
        // 해당 칼러로 먹을 수 있는 값을 계속 합쳐줌
        colorSum[ball.color] += ball.size;

        ans[ball.id] = prefixSum[ball.size] - prefixSumOfColor[ball.color][ball.size];
    }

    for (auto i : ans) {
        cout << i << '\n';
    }
}