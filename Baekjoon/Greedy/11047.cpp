#include<iostream>
#include<algorithm>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[10];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ret = 0;
    for (int i = n-1; i >= 0; i--){
        if (k / arr[i] == 0)
            continue;

        ret += k / arr[i];
        k %= arr[i];
    }
    cout << ret;
}