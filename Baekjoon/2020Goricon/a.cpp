//
// Created by LeeChanYoung on 2020/11/08.
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

int n;
char words[101][101];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            words[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++) {;
        for(int j = 0; j < n; j++){
            if (words[i][j] != words[j][i]){
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}