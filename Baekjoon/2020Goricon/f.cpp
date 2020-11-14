//
// Created by CY on 2020-11-08.
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
vector<int> arr;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = N-1; i >= N/2; i--){
        ans += arr[i] * 2;
    }

    if (N % 2 == 1){
        ans -= arr[N/2];
    }

    cout << ans;
}