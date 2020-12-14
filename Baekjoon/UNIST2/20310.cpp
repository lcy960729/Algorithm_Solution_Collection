//
// Created by LeeChanYoung on 2020/12/11.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <deque>

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

    string s;
    cin >> s;
    deque<pii> zer, one;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0') zer.emplace_back(i, 0);
        else one.emplace_back(i, 1);
    }
    int n = zer.size(), m = one.size();
    for(int i=0; i<n/2; i++) zer.pop_back();
    for(int i=0; i<m/2; i++) one.pop_front();
    deque<pii> res;
    merge(zer.begin(),zer.end(), one.begin(),one.end(), back_inserter(res));
    for(auto i : res) cout << i.second;
}
