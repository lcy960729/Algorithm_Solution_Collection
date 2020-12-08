#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll x[2000];

int main(){
    for (ll i = 0; i < 2000; i++){
        x[i] = i * (i + 1) / 2;
    }
    int n;
    cin >> n;
    while(n--){
        int v;
        cin >> v;
        int pos = lower_bound(x, x + 2000, v) - x;
        if(v + 1 == x[pos]){
            cout << pos + 1 << endl;
        } else if(v == x[pos]){
            cout << pos << endl;
        } else {
            cout << pos << endl;
        }
    }
}