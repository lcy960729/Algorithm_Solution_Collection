//
// Created by LeeChanYoung on 2020/12/29.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

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
        int n;
        cin >> n;

        if (n == 1) {
            cout << n << "\n";
            continue;
        }

        string visited[20001] = {};

        queue<int> q;
        q.push(1);
        visited[1] = "1";

        bool check = false;
        while (!q.empty()) {
            int num = q.front();
            q.pop();

            if (num == 0) {
                check = true;
                break;
            }

            int temp = (num * 10) % n;
            if (visited[temp].empty()) {
                q.push(temp);
                visited[temp] = visited[num] + '0';
            }

            temp = (temp + 1) % n;
            if (visited[temp].empty()) {
                q.push(temp);
                visited[temp] = visited[num] + '1';
            }
        }

        cout << (check ? visited[0] : "BRAK") << "\n";
    }
}