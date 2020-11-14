//
// Created by lcy96 on 2020-09-28.
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

string answer;

bool findAnswer = false;

bool isSatisfy(string &s) {
    int len = s.length() / 2;
    int start = s.length();

    for (int i = 1; i <= len; ++i) {
        if (s.substr(start-i, i) == s.substr(start-2*i, i)) {
            return false;
        }
    }
    return true;
}

void dfs(int len) {
    if (len == N) {
        findAnswer = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        answer.push_back(i + '0');

        if (isSatisfy(answer)){
            dfs(len + 1);
        }

        if (findAnswer)
            return;

        answer.pop_back();
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    dfs(0);
    cout << answer << "\n";
}
