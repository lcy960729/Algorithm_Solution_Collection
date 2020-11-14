#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int arr[100001];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int a;
    cin >> a;

    int b;
    cin >> b;

    int c;
    cin >> c;

    long double left = 0.000000001, mid = 0, right = 100000+0.000000001;

    while (left + 0.000000001 < right)
    {
        mid = (left + right) / 2 ;

        long double ret = a*mid + b*sin(mid);

        if (ret <= c)
            left = mid;
        else
            right = mid;
    }
    
    cout.fixed;
    cout.precision(18);
    cout << left << "\n";
}