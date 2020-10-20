//
// Created by lcy96 on 2020-09-22.
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

int t, n, m;
bool areFriends[10][10]={};

int countPairings(bool hasPartner[]){
    int firstPersonWithoutFriends = -1;

    for (int i = 0; i < n; ++i){
        if (!hasPartner[i]){
            firstPersonWithoutFriends = i;
            break;
        }
    }

    if (firstPersonWithoutFriends == -1)
        return 1;

    int ret = 0;

    for (int nextPerson = firstPersonWithoutFriends + 1; nextPerson < n; ++nextPerson){
        if (!hasPartner[nextPerson] && areFriends[firstPersonWithoutFriends][nextPerson]){
            hasPartner[firstPersonWithoutFriends] = hasPartner[nextPerson] = true;
            ret += countPairings(hasPartner);
            hasPartner[firstPersonWithoutFriends] = hasPartner[nextPerson] = false;
        }
    }

    return ret;
}


int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;

    while(t--){
        memset(areFriends, false, sizeof(areFriends));

        cin >> n >> m;

        while(m--){
            int a, b;
            cin >> a >> b;

            areFriends[a][b] = areFriends[b][a] = true;
        }
        bool token[10] = {};
        cout << countPairings(token) << "\n";
    }
}