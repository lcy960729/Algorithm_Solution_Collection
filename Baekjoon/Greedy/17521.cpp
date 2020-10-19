#include<iostream>
#include<algorithm>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    long long w;
    cin >> w;

    int s[15];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    long long coin = 0;
    for (int i = 0; i < n-1; i++){
        if (s[i] > s[i+1]){
            w += coin * s[i];
            coin = 0;
        }else if (s[i] < s[i+1]){
            coin += w / s[i];
            w = w % s[i];
        }
    }

    cout <<  w + coin * s[n-1];
}