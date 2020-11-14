#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[6562][6562];

void dc(int rowSize, int colSize, int row, int col)
{
    if (rowSize == 3 && colSize == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            arr[row][col + i] = (i == 2) ? '*' : ' ';
            arr[row + 1][col + i] = (i % 2 == 1) ? '*' : ' ';
            arr[row + 2][col + i] = '*';
        }
        return;
    }

    int nextRow = rowSize/2;
    int nextCol = colSize/2;

    dc(nextRow, nextCol, row, col + (nextCol/2)+1);
    dc(nextRow, nextCol, row + nextRow, col);
    dc(nextRow, nextCol, row + nextRow, col + nextCol+1);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(arr,' ',sizeof(arr));

    int n;
    cin >> n;

    dc(n, (n/3)*6-1, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n+1; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}