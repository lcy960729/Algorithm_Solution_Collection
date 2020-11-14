//
// Created by LeeChanYoung on 2020/11/08.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n;
vector<int> vote (102);


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int player;
        cin >> player;

        vote[player]++;
    }

    stack<pii > st;
    st.push({vote[1], 1});

    for (int i = 2; i <= n; i++) {
        if (vote[i] == 0)
            continue;

        if (!st.empty() && vote[i] >= st.top().first) {
            while(!st.empty() && vote[i] > st.top().first){
                st.pop();
            }

            st.push({vote[i], i});
        }
    }

    if (st.size() == 1) {
        cout << st.top().second << "\n";
    } else {
        cout << "skipped\n";
    }
}