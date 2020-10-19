//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

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

    string str, c4;
    cin >> str >> c4;

    int idx = 0;
    char result[1000001];

    for (char i : str) {
        result[idx++] = i;

        if (result[idx-1] == c4[c4.length()-1]) {
            if (idx - c4.length() < 0)
                continue;

            bool detected = true;
            for (int j = 0; j < c4.length(); j++) {
                if (result[idx-j-1] != c4[c4.length()-1 - j]) {
                    detected = false;
                    break;
                }
            }

            if (detected){
                for (int j = 0; j < c4.length(); j++)
                    result[idx - 1 - j] = '\0';

                idx -= c4.length();
            }
        }
    }

    if (!idx)
        cout << "FRULA";
    else {
        cout << result;
    }
}