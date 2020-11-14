#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

string dbj[500001];

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    
    int m;
    cin >> m;

    set<string> s;

    int index = 0;

    for (int i = 0; i < n+m; i++){
        string name;
        cin >> name;
        
        if (s.find(name) == s.end()){
            s.insert(name);
        }else{
            dbj[index++] = name;
        }
    }

    sort(dbj, dbj+index);

    cout << index << "\n";
    for (int i = 0; i < index; i++){
        cout << dbj[i] << "\n";
    }
}