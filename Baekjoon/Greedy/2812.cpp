//
// Created by LeeChanYoung on 2020/11/13.
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

int N, K;
stack<int> st;
string str;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K >> str;

    for (int i = 0; i < str.size(); i++) {
        while (!st.empty() && K > 0 && st.top() < str[i]) {
            --K;
            st.pop();
        }

        st.push(str[i]);
    }

    while (K) {
        st.pop();
        --K;
    }

    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
}