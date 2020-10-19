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

struct Trie{
private:
    bool isTerminal = false;
    Trie *children[26] = {};
    int numOfChildren = 0;

public:
    ~Trie(){
        for (auto i : children)
            delete i;
    }

    void insert(string &s){
        Trie *cur = this;

        for (char c : s){
            int index = c - 'a';

            if (!cur->children[index]){
                cur->children[index] = new Trie;
                cur->numOfChildren++;
            }

            cur = cur->children[index];
        }

        cur->isTerminal = true;
    }

    int fun(string &s, bool isRoot){
        Trie *cur = this;

        int result = s.length();

        for (char c : s){
            int index = c - 'a';

            if (cur->numOfChildren == 1 && !cur->isTerminal && !isRoot){
                result--;
            }

            cur = cur->children[index];
            isRoot = false;
        }
        return result;
    }

};

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    while(!cin.eof() && cin >> n){
        Trie trie;

        vector<string> str;
        for (int i = 0; i < n; i++){
            string s;
            cin >> s;

            str.push_back(s);
            trie.insert(s);
        }

        double ans = 0;
        for (int i = 0; i < n; i++){
            ans += trie.fun(str[i], true);
        }
        ans /= str.size();

        cout.precision(2);
        cout << fixed;

        cout << ans << "\n";
    }
}