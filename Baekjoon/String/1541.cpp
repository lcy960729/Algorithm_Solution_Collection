//
// Created by lcy96 on 2020-09-08.
//
//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>

#define pii pair<int, int>
#define ll long long

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int answer = 0;

    bool isMinusValue = false;
    int lastIndex = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.length()) {
            int num = stoi(s.substr(lastIndex, i - lastIndex));

            answer += (isMinusValue ? -num : num);

            if (!isMinusValue && s[i] == '-')
                isMinusValue = true;

            lastIndex = i + 1;
        }
    }

    cout << answer << "\n";
}

