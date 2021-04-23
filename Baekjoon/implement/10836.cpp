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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<int> grow(2 * M - 1, 1);

    // 겹치는 부분을 잘생각해야함 왼쪽, 왼쪽 위, 위라면 왼쪽 위와 위의 값은 이미 위에서 계산된거임
    // 그렇기 고대로 따라가면서 계산하면됨

    while (N--) {
        int zero, one, two;
        cin >> zero >> one >> two;

        for (int i = zero; i < zero + one; ++i) {
            grow[i]++;
        }
        for (int i = zero + one; i < grow.size(); ++i) {
            grow[i] += 2;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j == 0) {
                cout << grow[(M - 1 - i)] << ' ';
            } else {
                cout << grow[(M + j - 1)] << ' ';
            }
        }
        cout << '\n';
    }
}