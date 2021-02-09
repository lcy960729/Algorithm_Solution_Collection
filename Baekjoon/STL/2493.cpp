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

    int n;
    cin >> n;

    stack<pii > st;

    for (int i = 1; i <= n; ++i) {
        int height;
        cin >> height;

        while (!st.empty()) {
            if (height <= st.top().first)
                break;

            st.pop();
        }

        if (!st.empty()) {
            cout << st.top().second;
        } else {
            cout << '0';
        }

        cout << ' ';
        st.push({height, i});
    }
}