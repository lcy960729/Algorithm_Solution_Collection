//
// Created by lcy96 on 2020-09-16.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> numOfFriends;

string find(string name){
    if (parent.find(name) == parent.end()){
        return name;
    }

    parent[name] = find(parent[name]);
    return parent[name];
}

void insertMapItem(string name){
    if (numOfFriends.find(name) == numOfFriends.end()){
        numOfFriends.insert({name, 1});
    }
}

void merge(string a, string b){
    string parentA = find(a);
    string parentB = find(b);

    if (parentA == parentB)
        return;

    insertMapItem(parentA);
    insertMapItem(parentB);

    numOfFriends[parentA] += numOfFriends[parentB];
    parent[parentB] = parentA;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int f;
        cin >> f;

        for (int j = 0; j < f; j++){
            string s, d;
            cin >> s >> d;

            merge(s,d);
            cout << numOfFriends[find(s)] << "\n";
        }
        parent.clear();
        numOfFriends.clear();
    }
}