#include<iostream>
#include<algorithm>

using namespace std;
char arr[65][65];

void quadTree(int row, int col, int n){
    if (n==1){
        cout << arr[row][col];
        return ;
    }

    char t = arr[row][col];
    bool check = true;

    for (int i = 0; i <n; i++){
        for (int j = 0; j < n; j++){
            check &= (arr[row+i][col + j] == t);
        }
    }

    if (check){
        cout << t;
    }else {
        cout << "(";
        quadTree(row, col, n/2);
        quadTree(row, col+n/2, n/2);
        quadTree(row+n/2, col, n/2);
        quadTree(row+n/2, col+n/2, n/2);
        cout << ")";
    }
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >>arr[i][j];
        }
    }

    quadTree(0,0,n); 
}
