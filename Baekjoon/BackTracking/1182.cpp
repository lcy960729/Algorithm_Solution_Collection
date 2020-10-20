//
// Created by lcy96 on 2020-09-23.
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

int N;
int S;
int arr[21];
bool selected[21] = {};
int answer = 0;

void fun(int index) {
    if (k == N) {
        int sum = 0;
        bool check = false;

        for (int i = 0; i < N; i++) {
            if (selected[i]) {
                sum += arr[i];
                check = true;
            }
        }

        if (sum == S && check)
            answer++;

        return;
    }

    selected[k] = true;
    dfs(k + 1);
    selected[k] = false;
    dfs(k + 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    dfs(0);

    cout << answer << "\n";
}