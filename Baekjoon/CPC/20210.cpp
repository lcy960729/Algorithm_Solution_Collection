//
// Created by LeeChanYoung on 2020/12/06.
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

bool isUpper(char c) {
    return ('A' <= c && c <= 'Z');
}

bool isDigit(char c) {
    return ('0' <= c && c <= '9');
}

int cmpS(const string &s1, const string &s2) {
    if (isDigit(s1[0]) && !isDigit(s2[0])) return -1;
    else if (!isDigit(s1[0]) && isDigit(s2[0])) return 1;
    else if (isDigit(s1[0]) && isDigit(s2[0])) {
        int zeroCnt_w1 = 0, zeroCnt_w2 = 0;
        string w1, w2;

        for (int i = 0; i < max(s1.size(), s2.size()); ++i) {
            if (i < s1.size()) {
                if (w1.empty() && s1[i] == '0') zeroCnt_w1++;
                else w1 += s1[i];
            }

            if (i < s2.size()) {
                if (w2.empty() && s2[i] == '0') zeroCnt_w2++;
                else w2 += s2[i];
            }
        }

        if (w1.size() < w2.size()) return -1;
        if (w1.size() > w2.size()) return 1;
        if (w1 < w2) return -1;
        if (w1 > w1) return 1;
        if (zeroCnt_w1 < zeroCnt_w2) return -1;
        if (zeroCnt_w1 > zeroCnt_w2) return 1;
    } else if (!isDigit(s1[0]) && !isDigit(s2[0])) {
        for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
            if ((isUpper(s1[i]) && isUpper(s2[i])) || (!isUpper(s1[i]) && !isUpper(s2[i]))) {
                if (s1[i] < s2[i]) return -1;
                if (s1[i] > s2[i]) return 1;
            } else {
                if (toupper(s1[i]) < toupper(s2[i])) return -1;
                if (toupper(s1[i]) > toupper(s2[i])) return 1;
                if (toupper(s1[i]) == toupper(s2[i]) && isUpper(s1[i])) return -1;
                if (toupper(s1[i]) == toupper(s2[i]) && !isUpper(s1[i])) return 1;
            }
        }
    }

    if (s1.size() < s2.size()) return -1;
    if (s1.size() > s2.size()) return 1;
    return 0;
}

bool comVs(const vector<string> &vs1, const vector<string> &vs2) {
    for (int i = 0; i < min(vs1.size(), vs2.size()); ++i) {
        int result = cmpS(vs1[i], vs2[i]);
        if (result == -1) return true;
        if (result == 1) return false;
    }
    return vs1.size() < vs2.size();
}

vector<string> getWords(string &s) {
    vector<string> result;
    for (int i = 0; i < s.size(); ++i) {
        string w;

        bool type = isDigit(s[i]);
        for (int k = 0; type == isDigit(s[i + k]) && s.size() > i + k; k++)
            w += s[i + k];

        i += w.size() - 1;

        result.push_back(w);
    }

    return result;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<string>> vvs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vvs.push_back(getWords(s));
    }

    sort(vvs.begin(), vvs.end(), comVs);

    for (auto i : vvs) {
        for (auto j : i) {
            cout << j;
        }
        cout << '\n';
    }
}