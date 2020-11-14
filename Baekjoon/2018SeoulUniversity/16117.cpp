#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>

using namespace std;

int map[1001][1001] = {};
int memo[1001][1001][4];
int n, m;

int dp(int y, int x, int dir){
    if ((x > m || x < 0) || (y > n || y <= 0))
        return 0;

    if (x == m){
        if (dir != 2)
            return map[y][x];
        else
            return 0;
    }

    if (memo[y][x][dir] != -1){
        return memo[y][x][dir];
    }

    int result = 0;
    if (dir == 2){
        result = dp(y, x+1, 3);
    }else{
        result = max(
            {dp(y-1, x+1,0)
            ,dp(y+1, x+1,1)
            ,dp(y, x+1, 2)});
    }

    memo[y][x][dir] = result += map[y][x];
    cout << y << " : " << x << " : " << result << "\n";
    return memo[y][x][dir];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif


    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
            cin >> map[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));

    dp(3,0,0);

    cout << 1 << "\n";
}