#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int x, n;
    cin >> x >> n;

    n /= 2;

    if (n % 2 == 1 && n != 1)
        cout << "ERROR" << "\n";
    else if (n == 0)
        cout << "INFINITE" << "\n";
    else{
        if (n==1)
        x *= -1;
        
        int ans = x / n;
        cout << (x % n == 0 ? ans-1 : ans) << "\n";
    }
}