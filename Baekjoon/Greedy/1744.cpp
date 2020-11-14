//
// Created by LeeChanYoung on 2020/11/12.
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
vector<int> pos;
vector<int> neg;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num > 1) {
            pos.push_back(num);
        } else if (num <= 0) {
            neg.push_back(num);
        } else {
            ans += num;
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<>());

    int i = pos.size() - 1;
    while (i >= 0) {
        if (i > 0) {
            ans += pos[i] * pos[i - 1];
            i -= 2;
        } else {
            ans += pos[i];
            i--;
        }
    }

    i = neg.size() - 1;
    while (i >= 0) {
        if (i > 0) {
            ans += neg[i] * neg[i - 1];
            i -= 2;
        } else {
            ans += neg[i];
            i--;
        }
    }
    cout << ans;
}