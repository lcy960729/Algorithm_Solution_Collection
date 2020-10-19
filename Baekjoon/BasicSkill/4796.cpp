#include<iostream>
#include<algorithm>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int l,p,v;
    int count = 1;    

    while (true){
        cin >> l;
        cin >> p;
        cin >> v;

        if (l ==0 && p == 0 && v == 0)
            return 0;

        int ret = (v / p) * l;
        ret += ((v % p) > l) ? l : (v % p);        
        
        cout << "Case " << count++ << ": " << ret << "\n";
    }
}