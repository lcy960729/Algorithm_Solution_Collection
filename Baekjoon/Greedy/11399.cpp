#include<iostream>
#include<algorithm>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n, less<>());

    int ret = 0;
    for (int i = 0; i < n; i++){
        int temp = 0;
        
       for (int j = 0; j <= i; j++){
           temp += arr[j];
       }

       ret += temp;
    }

    cout << ret;
}