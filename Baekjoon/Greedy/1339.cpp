//
// Created by LeeChanYoung on 2020/11/10.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int n;
vector<string> arr(10);
int alphabet[26] = {};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        string &s = arr[i];
        int pow = 1;

        for (int j = s.length() - 1; j >= 0; j--) {
            int tmp = s[j]-'A';
            alphabet[tmp] += pow;
            pow *= 10;
        }
    }

    sort(alphabet, alphabet + 26, greater<>());

    int ans = 0;
    int num = 9;
    for (int i : alphabet) {
        if (i == 0) break;
        ans += (i * num--);
    }

    cout << ans;
}