#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[6562][6562];

void dc(int size, int row, int col)
{
    if (size == 3)
    {
        for (int i = 0; i < 3; i++)
        {
                arr[row][col + i] = '*';
                arr[row + 1][col + i] = (i == 1) ? ' ' : '*';
                arr[row + 2][col + i] = '*';
        }
        return;
    }

    int nextSize = size/3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 1 && j == 1)
                continue;

            dc(nextSize, row + i*nextSize, col + j*nextSize);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(arr,' ',sizeof(arr));

    int n;
    cin >> n;

    dc(n, 0, 0);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }

}