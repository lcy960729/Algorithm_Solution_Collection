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

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 행의 등차가 0일때부터 8일때까지
    // 열의 등차가 0일때부터 8일때까지

    // i,j의 등차

    int ans = -1;
    for (int y_degree = -8; y_degree < 9; ++y_degree) {
        for (int x_degree = -8; x_degree < 9; ++x_degree) {
            if (y_degree == 0 && x_degree == 0) continue;

            // 열과 인덱스
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    int y = i, x = j;
                    string numStr;
                    while (true) {
                        if (x < 0 || x >= m || y < 0 || y >= n)
                            break;

                        numStr += arr[y][x];

                        int num = stoi(numStr);
                        int square = (int) sqrt(num);

                        if (num == square * square) {
                            ans = max(ans, num);
                        }

                        y += y_degree;
                        x += x_degree;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}