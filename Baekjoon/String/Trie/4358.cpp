//
// Created by lcy96 on 2020-09-10.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Trie {
private:
    Trie *children[95] = {};
    double numOfWord = 0;
    bool isTerminal = false;
    string str;

public:
    ~Trie() {
        for (auto i: children) {
            delete i;
        }
    }

    void insert(string &s) {
        Trie *cur = this;

        for (char c : s) {
            int index = c - ' ';

            if (!cur->children[index]) {
                cur->children[index] = new Trie;
            }

            cur = cur->children[index];
        }

        cur->str = s;
        cur->numOfWord++;
        cur->isTerminal = true;
    }

    void print(int n, Trie *trie) {
        for (auto & child : trie->children) {
            if (!child)
                continue;

            if (child->isTerminal) {
                cout << child->str << " ";

                double ratio = child->numOfWord / (double) n * 100;

                cout << fixed;
                cout.precision(4);
                cout << ratio << "\n";
            }

            print(n, child);
        }
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Trie *root = new Trie();

    string s;
    int i = 0;
    while (!cin.eof() && getline(cin, s)) {
        root->insert(s);
        i++;
    }

    root->print(i, root);
}