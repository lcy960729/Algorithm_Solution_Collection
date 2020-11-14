//
// Created by lcy96 on 2020-09-08.
//
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++){
        cout << str[i];
        if (i % 10 == 9)
            cout << "\n";
    }
}