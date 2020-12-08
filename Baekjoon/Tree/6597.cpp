//
// Created by LeeChanYoung on 2020/11/21.
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

void postOrder(string pre, string in) {
    if (!pre.length())
        return;

    int size = pre.size();

    const char root = pre[0];

    const int left = find(in.begin(), in.end(), root) - in.begin();
    const int right = size - left - 1;

    postOrder(pre.substr(1, left), in.substr(0, left));
    postOrder(pre.substr(left + 1, right), in.substr(left + 1, right));

    cout << root;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string pre;
    string in;

    while (true) {
        cin >> pre >> in;

        if (!pre.length())
            break;

        postOrder(pre, in);
        cout << "\n";
    }
}