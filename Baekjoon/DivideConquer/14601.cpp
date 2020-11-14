#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[128][128];
int cnt = 1;

void dc(int n, int row, int col, pair<int, int> waterspout)
{
    if (n == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if ((row + i == waterspout.first) && (col + j == waterspout.second))
                    continue;

                arr[row + i][col + j] = cnt;
            }
        }
        cnt++;
        return;
    }

    int quadrant  = 0;
    
    pair<int, int> nextWaterspout[4];
    nextWaterspout[0] = {row + n / 2 - 1, col + n / 2 - 1};
    nextWaterspout[1] = {row + n / 2 - 1, col + n / 2};
    nextWaterspout[2] = {row + n / 2, col + n / 2 - 1};
    nextWaterspout[3] = {row + n / 2, col + n / 2};

    if (waterspout.first < row + n / 2)
    {
        if (waterspout.second < col + n / 2)
            quadrant = 0;
        else
            quadrant = 1;
    }
    else
    {
        if (waterspout.second < col + n / 2)
            quadrant = 2;
        else
            quadrant = 3;
    }
    nextWaterspout[quadrant] = waterspout;

    for (int i = 0; i < 4; i++){
        if (quadrant == i)
            continue;
        arr[nextWaterspout[i].first][nextWaterspout[i].second] = cnt;
    }
    cnt++;

    for (int i = 0, k=0; i < 2; i++){
        for (int j = 0; j < 2; j++, k++){
            int nextSize = n/2;
            int nextRow = row +nextSize * i;
            int nextCol = col + nextSize * j;

            dc(nextSize, nextRow, nextCol, nextWaterspout[k]);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(arr, 0, sizeof(arr));

    int n;
    cin >> n;
    n = 1 << n;

    pair<int, int> waterspout;
    cin >> waterspout.second;
    cin >> waterspout.first;

    waterspout.first = n - waterspout.first;
    waterspout.second = waterspout.second - 1;

    arr[waterspout.first][waterspout.second] = -1;
    dc(n, 0, 0, waterspout);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(3);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}