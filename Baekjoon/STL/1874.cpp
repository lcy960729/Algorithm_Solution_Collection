//
// Created by LeeChanYoung on 2020/12/22.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

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

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    stack<int> st;
    vector<char> ans;

    int cur = 0;
    int value = 0;
    for (int i = 1; i <= n; ++i) {
        while (st.empty() || (a[cur] > st.top())) {
            st.push(++value);
            ans.push_back('+');
        }

        if (st.top() == a[cur]) {
            ans.push_back('-');
            st.pop();
            cur++;
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (char &c : ans) {
        cout << c << "\n";
    }
}
