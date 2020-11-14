//
// Created by lcy96 on 2020-09-21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

map<string, string> parent;
vector<pair<string, string>> notEquals;

map<string, int> table;

string find(const string &id) {
    if (parent.find(id) == parent.end()) {
        return id;
    }

    parent[id] = find(parent[id]);
    return parent[id];
}

void addTable(string &a, string &b) {
    bool isNumberA = isdigit(a.back());
    bool isNumberB = isdigit(b.back());

    if (!isNumberA && !isNumberB)
        return;

    int numA = isNumberA ? stoi(a) : 0;
    int numB = isNumberB ? stoi(b) : 0;

    if (isNumberA && isNumberB) {
        if (numA == numB)
            return;

        cout << "1==0" << "\n";
        exit(0);
    }

    a=find(a);
    b=find(b);

    if (isNumberA){
        if (table.find(b) != table.end() && table[b] != numA){
            cout << "1==0" << "\n";
            exit(0);
        }

        table[b] = numA;
    } else {
        if (table.find(a) != table.end() && table[a] != numB){
            cout << "1==0" << "\n";
            exit(0);
        }

        table[a] = numB;
    }
}


void uni(string &a, string &b) {
    string parentA = find(a);
    string parentB = find(b);

    if (parentA == parentB)
        return;

    if (parentA.length() < parentB.length()){
        swap(parentA, parentB);
    }

    if (table.find(parentA) != table.end() ){
        if (table.find(parentB) != table.end()){
            if (table[parentA] != table[parentB]) {
                cout << "1==0";
                exit(0);
            }
        }
        table[parentB] = table[parentA];
    }


    parent[parentA] = parentB;

    addTable(a, b);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    string word;

    for (int i = 0; i <= s.length(); i++) {
        char &c = s[i];

        if (c == '&' || c == '\0') {

            if (word.empty())
                continue;

            string a, b;
            if (word.find("==") != string::npos) {
                a = word.substr(0, word.find("=="));
                b = word.substr(word.find("==") + 2);

                uni(a, b);
            } else {
                a = word.substr(0, word.find("!="));
                b = word.substr(word.find("!=") + 2);

                notEquals.push_back({a, b});
            }

            word.clear();
        } else {
            word += c;
        }
    }

    set<pair<string, string>> done;

    for(pair<string, string> pss : notEquals){
        string a = find(pss.first);
        string b = find(pss.second);

        if (a > b)
            swap(a,b);

        bool isNumberA = isdigit(a.back());
        bool isNumberB = isdigit(b.back());

        if (a == b) {
            cout << "1==0";
            return 0;
        }

        if (table.find(a) != table.end() && table.find(b) != table.end()){
            continue;
        }

        if (isNumberA && isNumberB)
            continue;

        done.insert({a,b});
    }

    if (parent.empty() && done.empty()){
        cout << "1==1";
    }else {
        bool first = true;
        for (auto s : parent) {
            if (first)
                first = false;
            else
                cout << "&&";

            string res;
            if (s.first != (res = find(s.first)))
                cout << s.first << "==" << res;
        }

        for(auto s : done){
            if (first)
                first = false;
            else
                cout << "&&";
            cout << s.second << "!=" << s.first;
        }
    }
}