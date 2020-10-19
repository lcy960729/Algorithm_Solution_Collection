#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];

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

    long long left = 0, mid = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        right = max((int)right, arr[i]);
    }
    
    right++;

    while (left + 1 < right)
    {
        long long sum = 0;
        mid = left + right >> 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= mid)
                sum += arr[i] / mid;
        }

        if (sum >= m){
            left = mid;
        }
        else 
            right = mid;
    }

    cout << left << "\n";
}