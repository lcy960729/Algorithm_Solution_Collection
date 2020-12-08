//
// Created by LeeChanYoung on 2020/12/07.
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

int getDist(pii p1, pii p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

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
        int n, k;
        cin >> n >> k;

        vector<pii > point(n);


        for (int i = 0; i < n; i++) {
            cin >> point[i].first;
            cin >> point[i].second;
        }

        bool check;
        for (int i = 0; i < n; i++) {
            check = true;
            for (int j = 0; j <n; j++) {
                if (i == j)
                    continue;

                if (getDist(point[i], point[j]) > k) {
                    check = false;
                    break;
                }
            }
            if (check)
                break;
        }

        cout << (check ? 1 : -1) << "\n";
    }
}
