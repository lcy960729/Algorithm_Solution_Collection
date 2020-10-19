//
// Created by lcy96 on 2020-09-09.
//

//
// Created by lcy96 on 2020-09-04.
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

struct Trie {

private:
    bool isTerminal = false;
    bool hasChild = false;
    Trie *children[10] = {};

public:
    ~Trie() {
        for (auto i : children) {
            delete i;
        }
    }

    bool insert(string &s) {
        Trie *cur = this;

        for (char c : s) {
            int index = c - '0';

            if (cur->isTerminal)
                return false;

            if (!cur->children[index]) {
                cur->children[index] = new Trie;
                cur->hasChild = true;
            }
            cur = cur->children[index];
        }

        cur->isTerminal = true;

        if (cur->isTerminal && cur->hasChild)
            return false;

        return true;
    }

    bool find(string &s) {
        Trie *cur = this;

        for (char c : s) {
            int index = c - '0';
            if (!cur->children[index])
                return false;

            cur = cur->children[index];
        }

        return cur->isTerminal;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;

        Trie root;

        bool check = true;

        vector<string> s;
        for (int j = 0; j < n; j++){
            string str;
            cin >> str;

            s.push_back(str);
        }

        for (int j = 0; j < n; j++){
            string str = s[j];
            check = root.insert(str);

            if (!check)
                break;
        }

        cout << (check ? "YES" : "NO") << "\n";
    }
}