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
    while(!cin.eof() && getline(cin, str)){
        cout << str << "\n";
    }
}