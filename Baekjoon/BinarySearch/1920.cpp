#include <iostream>
#include <algorithm>

using namespace std;

bool check(int x, int num)
{
    return x <= num;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int arr[100001];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, less<int>());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        int begin = 0, end = n;
        while (begin + 1 < end)
        {
            int mid = begin + end >> 1;
            if (check(arr[mid], num))
                begin = mid;
            else
                end = mid;
        }

        if (arr[begin] == num)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}