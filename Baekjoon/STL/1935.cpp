#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
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

    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<int> operand(N + 2);
    for (int &i : operand) {
        cin >> i;
    }

    stack<double> st;
    for (char &i : s) {
        double ret;

        if ('A' <= i && i <= 'Z') {
            ret = operand[i - 'A'];
        } else {
            double rhs = st.top();
            st.pop();
            double lhs = st.top();
            st.pop();

            if (i == '+') {
                ret = lhs + rhs;
            } else if (i == '-') {
                ret = lhs - rhs;
            } else if (i == '*') {
                ret = lhs * rhs;
            } else if (i == '/') {
                ret = lhs / rhs;
            }
        }

        st.push(ret);
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';
}