//
// Created by CY on 2020-10-30.
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
string s;
int visited[50] = {};

int fun(int start, int end) {
    int ret = 0;

    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            int k = s[i - 1] - '0';
            ret += k * fun(i + 1, visited[i]) - 1;
            i = visited[i];

            continue;
        }
        ret++;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            visited[st.top()] = i;
            st.pop();
        }
    }

    cout << fun(0, s.length());
}
