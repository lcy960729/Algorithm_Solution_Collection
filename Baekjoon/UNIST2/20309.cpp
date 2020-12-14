//
// Created by LeeChanYoung on 2020/12/11.
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

int N;
vector<int> even;
vector<int> odd;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (i % 2 == num % 2) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
