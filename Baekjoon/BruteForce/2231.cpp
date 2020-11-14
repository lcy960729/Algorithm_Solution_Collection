#include<iostream>

using namespace std;

int main(){
    int n, result = 0;
    cin >> n;

    for (int i = 1; i < n; i++){
        int sum = i;

        int j = 10;
        while (true){
            sum += (i % j) / (j / 10);

            if (i % j == i) {
                break;
            }
            else {
                j *= 10;
            }
        }

        if (sum == n){
            result = i;
            break;
        }

    }
    cout << result;
}