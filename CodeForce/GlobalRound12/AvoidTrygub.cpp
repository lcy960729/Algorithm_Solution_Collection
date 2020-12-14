//
// Created by LeeChanYoung on 2020/12/06.
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int length;
        cin >> length;

        string str;
        cin >> str;

        int s = 0;
        while (true) {
            int bIndex = str.find('b', s);

            if (bIndex == string::npos) {
                break;
            }

            swap(str[s], str[bIndex]);
            s++;
        }
        cout << str << "\n";
    }
}