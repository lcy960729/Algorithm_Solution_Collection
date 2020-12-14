//
// Created by LeeChanYoung on 2020/12/14.
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

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        stack<char> st;
        stack<char> st2;

        int ans = 0;
        for (char c : s) {
            if (c == '(' || c == ')') {
                if (c == ')') {
                    if (!st.empty() && st.top() == '(') {
                        ans++;
                        st.pop();
                    }
                }else{
                    st.push(c);
                }
            } else {
                if (c == ']') {
                    if (!st2.empty() && st2.top() == '[') {
                        ans++;
                        st2.pop();
                    }
                }else{
                    st2.push(c);
                }
            }
        }
        cout << ans << '\n';
    }
}
