//
// Created by lcy96 on 2020-10-06.
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

int N, M;
int pSum[1024*1024+1];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;

        pSum[i + 1] = pSum[i] + num;
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        x1--;
        y1--;
        x2--;
        y2--;

        int result = 0;
        for (int j = y1; j <= y2; j++){
            int s = j * N + x1 + 1;
            int e = j * N + x2 + 1;

            result += pSum[e] - pSum[s-1];
        }

        cout << result << "\n";
    }
}