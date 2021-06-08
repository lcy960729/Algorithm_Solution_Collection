#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int arr[] = {100, 100, 200, 200, 300, 300, 400, 400, 500};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> scores(9, 0);
    for (auto &i : scores) {
        cin >> i;
    }

    int sum = 0;
    for (int i = 0; i < scores.size(); ++i) {
        sum += scores[i];

        if (scores[i] > arr[i]) {
            cout << "hacker\n";
            return 0;
        }
    }

    if (sum >= 100){
        cout << "draw\n";
    }else{
        cout << "none\n";
    }
}