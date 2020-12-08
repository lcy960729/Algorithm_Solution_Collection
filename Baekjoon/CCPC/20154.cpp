//
// Created by LeeChanYoung on 2020/11/22.
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


bool alphabet[] = {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string K;
    cin >> K;

    bool ans = true;
    for (char c : K) {
        if (!alphabet[c - 'A']) {
            ans = !ans;
        }
    }

    if (ans) {
        cout << "You're the winner?";
    } else {
        cout << "I'm a winner!";
    }
}
