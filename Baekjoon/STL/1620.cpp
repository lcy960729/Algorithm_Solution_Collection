#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

string poketName[100000];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int m;
    cin >> m;

    map<string, int> poket;

    for (int i = 0; i < n; i++){
        string name;
        cin >> name;

        poket.insert({name, i+1});
        poketName[i+1] = name;
    }

    for (int i = 0; i < m; i++){
        string name;
        cin >> name;

        if (isdigit(name[0])){
            cout << poketName[stoi(name)] << "\n";
        }else{
            cout << poket[name] << "\n";
        }
    }
}