#include <iostream>

using namespace std;

long long multi(int a, int b, int c)
{
    if (b == 1)
        return a % c;

    long long  temp = multi(a, b / 2, c);
    long long  ret = (temp * temp) % c;

    if (b % 2 == 1)
        ret *= a % c;

    return ret % c;
}

int main()
{
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << multi(a, b, c);
}