#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;

    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i]; 
    }


    int max = 0;
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                int sum = a[i] + a[j] + a[k];

                if (sum <= m && sum > max){
                    max = sum;
                }
            }
        }
    }

    cout << max;
}