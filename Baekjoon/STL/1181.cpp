#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(string w1, string w2){
    if (w1.size() == w2.size()){
        return w1 < w2;
    }else{
        return w1.size() < w2.size();
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string word[20000];

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        word[i] = temp;
    }

    sort(word, word+n, cmp);

    for (int i = 0; i < n; i++){
        if (i != 0 && word[i].compare(word[i-1]) == 0)
            continue;
    
        cout << word[i] << "\n";
    }
}