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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(14);

    int seongminFunds = n, junhyunFunds = n;
    int seongminStock = 0, junhyunStock = 0;

    for (int i = 0; i < 14; ++i) {
        cin >> arr[i];

        //준현
        if (seongminFunds / arr[i]) {
            seongminStock = seongminFunds / arr[i];
            seongminFunds %= arr[i];
        }

        // 성민
        if (i >= 3) {
            if (arr[i] < arr[i - 1] && arr[i - 1] < arr[i - 2] && arr[i - 2] < arr[i - 3]) {
                // 내릴때
                if (junhyunFunds / arr[i]) {
                    junhyunStock = junhyunFunds / arr[i];
                    junhyunFunds %= arr[i];
                }
            } else if (arr[i] > arr[i - 1] && arr[i - 1] > arr[i - 2] && arr[i - 2] > arr[i - 3]) {
                // 오를때
                junhyunFunds += junhyunStock * arr[i];
                junhyunStock = 0;
            }
        }
    }

    seongminFunds += seongminStock * arr[13];
    junhyunFunds += junhyunStock * arr[13];

    if (seongminFunds > junhyunFunds) {
        cout << "BNP\n";
    } else if (seongminFunds < junhyunFunds) {
        cout << "TIMING\n";
    } else {
        cout << "SAMESAME\n";
    }
}