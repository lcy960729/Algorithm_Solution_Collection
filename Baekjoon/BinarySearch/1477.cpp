#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int m;
    cin >> m;

    int l;
    cin >> l;

    int arr[104];

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[n+1] = l;

    int size = n+2;

    sort(arr, arr + size);

    int left = 1, mid = 0, right = l-1;

    while (left +1 < right)
    {
        mid = left + right >> 1;
        
        int count = 0;

        for (int i = 1; i < size; i++){
            int distance = arr[i] - arr[i-1];
            if (distance > mid){
                count += (distance) / mid;

                if (distance % mid == 0)
                    count--;
            }
        }

        if (count > m)
            left = mid;
        else
            right = mid;
    }

    cout << right << "\n";
}