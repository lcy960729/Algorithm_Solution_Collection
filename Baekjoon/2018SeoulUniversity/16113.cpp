#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

const int number[9][5][3] = {
    //0
    {{1,1,1},{1,0,1},{1,0,1},{1,0,1},{1,1,1}},
    //2
    {{1,1,1},{0,0,1},{1,1,1},{1,0,0},{1,1,1}},
    //3
    {{1,1,1},{0,0,1},{1,1,1},{0,0,1},{1,1,1}},
    //4
    {{1,0,1},{1,0,1},{1,1,1},{0,0,1},{0,0,1}},
    //5
    {{1,1,1},{1,0,0},{1,1,1},{0,0,1},{1,1,1}},
    //6
    {{1,1,1},{1,0,0},{1,1,1},{1,0,1},{1,1,1}},
    //7
    {{1,1,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}},
    //8
    {{1,1,1},{1,0,1},{1,1,1},{1,0,1},{1,1,1}},
    //9
    {{1,1,1},{1,0,1},{1,1,1},{0,0,1},{1,1,1}}
};

int signalText[5][20001];

int checkNumber(int col){
    for (int k = 0; k < 9; k++){
        bool isFindNumber = true;
        
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 3; j++){
                if (signalText[i][j+col] != number[k][i][j]){
                    isFindNumber = false;
                    break;
                }
            }
            if (!isFindNumber)
                break;
        }

        if (isFindNumber)
            return k != 0 ? k+1 : k;
    }

    return 1;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    string text;
    cin >> text;

    for (int i = 0, index = 0; i < 5; i++){
        for (int j = 0; j < n/5; j++, index++)
        {
            signalText[i][j] = (text[index] == '#' ? 1 : 0);
        }
    }

    string ans = "";
    for (int i = 0; i < n/5; i++){
        if (signalText[0][i]){
            int num = checkNumber(i);
            if (num != 1){
                i += 2;
            }
            ans += to_string(num);
        }
    }

    cout << ans;
}