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
enum {
    UPPER = 0, LOWER = 1, DIGIT = 2
};

using namespace std;

int getType(char c) {
    if (c >= 'A' && c <= 'Z') {
        return UPPER;
    } else if (c >= 'a' && c <= 'z') {
        return LOWER;
    } else if (c >= '0' && c <= '9') {
        return DIGIT;
    }
    return 3;
}

bool isAlphabet(int type) {
    return ((type == UPPER || type == LOWER));
}

vector<pair<string, int>> getWords(const string &s) {
    vector<pair<string, int>> vs;

    for (int i = 0; i < s.size(); i++) {
        int type = getType(s[i]);

        if (isAlphabet(type)) {
            vs.push_back({{s[i]}, type});
        } else {
            string num;
            while (i < s.size() && !isAlphabet(getType(s[i]))) {
                num.push_back(s[i++]);
            }
            vs.push_back({num, type});
            --i;
        }
    }
    return vs;
}


bool compareStringInt(string &s1, string &s2) {
    int s1_zero = 0;
    int s2_zero = 0;

    reverse(s1.begin(), s1.end());
    int index = s1.size() - 1;
    while (index >= 0 && s1[index] == 0) {
        s1.pop_back();
        s1_zero++;
        index--;
    }
    reverse(s1.begin(), s1.end());

    reverse(s2.begin(), s2.end());
    index = s2.size() - 1;
    while (index >= 0 && s2[index] == 0) {
        s2.pop_back();
        s2_zero++;
        index--;
    }
    reverse(s2.begin(), s2.end());

    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            return s1[i] < s2[i];
        }
    }

    return s1_zero < s2_zero;
}

bool cmp(const string &s1, const string &s2) {
    vector<pair<string, int>> vs1 = getWords(s1);
    vector<pair<string, int>> vs2 = getWords(s2);

    int size = vs1.size() < vs2.size() ? vs1.size() : vs2.size();

    for (int i = 0; i < size; i++) {
        if (vs1[i].first == vs2[i].first) {
            continue;
        } else if (isAlphabet(vs1[i].second) && isAlphabet(vs2[i].second)) {
            return vs1[i].first < vs2[i].first;
        } else if (isAlphabet(vs1[i].second) && !isAlphabet(vs2[i].second)) {
            return true;
        } else if (isAlphabet(vs1[i].second) && !isAlphabet(vs2[i].second)) {
            return false;
        } else if (!isAlphabet(vs1[i].second) && !isAlphabet(vs2[i].second)) {
            return compareStringInt(vs1[i].first, vs2[i].first);
        }
    }
    return false;
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

    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }

    sort(vs.begin(), vs.end(), cmp);

    for (string str : vs) {
        cout << str << "\n";
    }
}