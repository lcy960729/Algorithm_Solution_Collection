#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>

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

    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if ('A' <= c && c <= 'Z') {
            cout << c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == '*' || c == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        } else if (c == '+' || c == '-') {
            while (!st.empty() && (st.top() != '(')) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && (st.top() != '(')) {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << '\n';
}