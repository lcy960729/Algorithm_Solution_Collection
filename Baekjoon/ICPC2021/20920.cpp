#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Word{
    string s;
    int cnt;
};

bool cmp(const Word &w1, const Word &w2){
    if (w1.cnt == w2.cnt){
        if (w1.s.length() == w2.s.length()){
            return w1.s < w2.s;
        }
        return w1.s.length() > w2.s.length();
    }
    return w1.cnt > w2.cnt;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s.length() < m)
            continue;

        if (mp.find(s) == mp.end())
            mp[s] = 0;

        mp[s]++;
    }


    vector<Word> words;
    for (auto i: mp){
        words.push_back({i.first, i.second});
    }

    sort(words.begin(), words.end(), cmp);

    for (auto word : words){
        cout << word.s << '\n';
    }
}