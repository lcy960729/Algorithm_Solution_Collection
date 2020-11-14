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
    Trie *children[2] = {};

public:
    ~Trie(){
        for (auto i : children)
            delete i;
    }

    void insert(string &s){
        Trie *cur = this;

        for (char c : s){
            int index = c - '0';

            if (!cur->children[index]){
                cur->children[index] = new Trie;
            }

            cur = cur->children[index];
        }
    }

    int find(string &s){
        Trie *cur = this;

        int depth = 29;

        int result = 0;
        for (char c : s){
            bool index = c - '0';

            if (!cur->children[!index]) {
                cur = cur->children[index];
            }
            else {
                cur = cur->children[!index];
                result += (1 << depth);
            }
            depth--;
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
    cin >> n;

    Trie root;

    int answer = 0;

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;

        string s;
        for (int j = 29; j >= 0; j--){
             if (num & (1 << j))
                 s.push_back('1');
             else
                 s.push_back('0');
        }

        root.insert(s);

        if (i != 0){
            answer = max(answer, root.find(s));
        }
    }
    cout << answer << "\n";
}