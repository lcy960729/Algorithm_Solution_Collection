//
// Created by LeeChanYoung on 2020/12/11.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int K, N;
pii cnt[300001];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    int check = 0;
    for (int i = 1; i <= K; i++) {
        cin >> cnt[i].first;
        cnt[i].second = i;

        check = max(check, cnt[i].first);
    }

    if (check > (N + 1) / 2) {
        cout << -1;
        return 0;
    }

    sort(cnt + 1, cnt + K + 1, greater<>());

    deque<int> ans;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < cnt[i].first; j++) {
            ans.push_back(cnt[i].second);
        }
    }
    for (int i = 0; i < (n + 1) / 2; i++) {
        a[i*2]
    }

    for (int a : ans) {
        cout << a << " ";
    }
}