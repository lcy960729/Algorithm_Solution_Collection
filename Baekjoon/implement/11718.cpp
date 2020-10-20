//
// Created by CY on 2020-09-28.
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



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int count[10] = {};

    int numOfMostNumber = 0;
    int numOfSixOrNine = 0;
    for (char i : str) {
        int num = i - '0';
        count[num]++;

        if (num == 6 || num == 9) {
            numOfSixOrNine++;
        } else {
            numOfMostNumber = max(numOfMostNumber, count[num]);
        }
    }

    if (numOfSixOrNine % 2 == 1) {
        numOfSixOrNine = numOfSixOrNine / 2 + 1;
    } else {
        numOfSixOrNine /= 2;
    }

    cout << max(numOfMostNumber, numOfSixOrNine);
}
