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

void combination(int size, vector<int> &prefixSum, map<int, int> &mp) {
    for (int i = 1; i <= size; ++i) {
        for (int j = i; j <= size + i - 1; ++j) {
            int sum = prefixSum[j] - prefixSum[j - i];

            mp[sum]++;

            if (i == size) break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int S;
    cin >> S;

    int M, N;
    cin >> M >> N;

    vector<int> pizzaA(M + 1);
    vector<int> sumA(2 * (M + 1), 0);
    for (int i = 1; i <= M; ++i) {
        cin >> pizzaA[i];
        sumA[i] = sumA[i - 1] + pizzaA[i];
    }
    for (int i = M + 1; i <= 2 * M; ++i) {
        sumA[i] = sumA[i - 1] + pizzaA[i - M];
    }

    vector<int> pizzaB(N + 1);
    vector<int> sumB(2 * (N + 1), 0);
    for (int i = 1; i <= N; ++i) {
        cin >> pizzaB[i];
        sumB[i] = sumB[i - 1] + pizzaB[i];
    }
    for (int i = N + 1; i <= 2 * N; ++i) {
        sumB[i] = sumB[i - 1] + pizzaB[i - N];
    }

    map<int, int> cntA, cntB;
    combination(M, sumA, cntA);
    combination(N, sumB, cntB);

    int ret = cntA[S] + cntB[S];
    for (int i = 1; i < S; ++i) {
        ret += cntA[i] * cntB[S - i];
    }

    cout << ret << '\n';
}