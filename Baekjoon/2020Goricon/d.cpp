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

double energyDrink[100001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> energyDrink[i];
    }

    sort(energyDrink, energyDrink+N, greater<>());

    for(int i = 1; i< N; i++){
        energyDrink[0] = energyDrink[0] + (energyDrink[i]/2);
    }
    cout << energyDrink[0];
}

