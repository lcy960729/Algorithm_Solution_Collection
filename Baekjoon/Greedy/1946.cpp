//
// Created by LeeChanYoung on 2020/11/11.
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

int t;
int n;

pii volunteer[100001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while(t--){
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> volunteer[i].first;
            cin >> volunteer[i].second;
        }

        sort(volunteer, volunteer + n);

        int interviewRank = 1e9;
        int ans = 0;

        for (int i = 0; i < n; i++){
            if (interviewRank >= volunteer[i].second){
                interviewRank = volunteer[i].second;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}
