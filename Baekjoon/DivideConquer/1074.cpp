#include <iostream>
#include <algorithm>
#include<cmath>

using namespace std;

long long r, c;
long long cnt = 0;
bool ret = false;

bool dc(int n, int x, int y)
{
    if (n == 2)
    {
        if (x == r && y == c)
        {
            return true;
        }
        cnt++;

        if (x == r && y + 1 == c)
        {
            return true;
        }
        cnt++;

        if (x + 1 == r && y == c)
        {
            return true;
        }
        cnt++;

        if (x + 1 == r && y + 1 == c)
        {
            return true;
        }
        cnt++;

        return false;
    }

    if (!ret)
        ret = dc(n/2, x, y);
    if (!ret)
        ret = dc(n/2, x, y+n/2);
    if (!ret)
        ret = dc(n/2, x+n/2, y);
    if (!ret)
        ret = dc(n/2, x+n/2, y+n/2);

    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;
    cin >> r;
    cin >> c;

    dc(pow(2,n), 0, 0);

    cout << cnt;
}