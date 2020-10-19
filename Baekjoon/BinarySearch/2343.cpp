#include <iostream>
#include <algorithm>

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

    int n;
    cin >> n;

    int m;
    cin >> m;

    long long left = 0, mid = 0, right = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        right += arr[i];
    }

    right++;

    while (left + 1 < right)
    {
        mid = left + right >> 1;

        int count = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++){

            if (count > m || arr[i] > mid){
                count = 1e9;
                break;
            }

            if (sum + arr[i] <= mid){
                sum += arr[i];
            }else{
                sum = arr[i];
                count++;
            }
        }

        if (count > m)
        {
            left = mid;
        }
        else
            right = mid;
    }

    cout << right << "\n";
}