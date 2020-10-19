#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int temp = (a*e - b*d);
    a /= temp;
    b /= -1*temp;
    d /= -1*temp;
    e /= temp;

    double x, y;
    x = e*c + b*f;
    y = d*c + a*f;

    cout << round(x) << " " << round(y);
}