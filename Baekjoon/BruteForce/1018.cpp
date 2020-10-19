#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n;
    cin >> m;

    char a[50][50];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int min = 64;

    for (int i = 0; i<= n-8; i++){
        for (int j = 0; j <= m-8; j++){
            int result = 0;
            char next = 'B';

            for (int row = 0; row < 8; row++){
                for (int col = 0; col < 8; col++){
                    if (a[i+row][j+col] != next)
                        result++;

                    next = (next == 'B') ? 'W' : 'B';
                }
                    next = (next == 'B') ? 'W' : 'B';
            }
               
            min = (min > result) ? result : min;
            min = (min > 64 - result) ? 64 - result : min;
        }
    }

    cout << min;
}