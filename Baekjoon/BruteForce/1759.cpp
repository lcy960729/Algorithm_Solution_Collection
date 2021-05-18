#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, C;
    cin >> L >> C;

    vector<char> alphabet(C);

    for (auto &i : alphabet) {
        cin >> i;
    }

    sort(alphabet.begin(), alphabet.end());

    vector<bool> check(C, false);
    for (int i = 0; i < L; ++i) {
        check[check.size() - 1 - i] = true;
    }

    set<string> ans;

    do {
        string s;
        int numOfConsonant = 0;
        int numOfVowel = 0;

        for (int i = 0; i < check.size(); ++i) {
            if (!check[i]) continue;

            if (isVowel(alphabet[i])) {
                numOfVowel++;
            } else {
                numOfConsonant++;
            }

            s += alphabet[i];
        }

        if (numOfVowel >= 1 && numOfConsonant >= 2) {
            ans.insert(s);
        }
    } while (next_permutation(check.begin(), check.end()));

    for (string str : ans) {
        cout << str << '\n';
    }
}