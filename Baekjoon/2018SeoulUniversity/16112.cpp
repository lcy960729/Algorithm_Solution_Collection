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

    int n, k;
    cin >> n >> k;

    int quest[300001];
    for (int i = 0; i < n; i++)
    {
        cin >> quest[i];
    }

    sort(quest, quest+n);

    long long ans = 0;
    long long sum = 0;
    for (int i = n-1; i >= 0; i--){
        if (i < k) ans+=sum;
        sum += (long long)quest[i];
    }

    cout << ans;
}