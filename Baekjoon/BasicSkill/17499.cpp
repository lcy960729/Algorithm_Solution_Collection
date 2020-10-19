#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int arr[200000];
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int begin = 0;
    for (int i = 0; i < q; i++)
    {
        int mode = 0;
        cin >> mode;

        int num = 0;
        if (mode == 1)
        {
            int index = 0;
            cin >> index >> num;
            arr[(begin + index - 1) % n] += num;
        }
        else
        {
            cin >> num;
            begin += (mode == 2) ? n - num : num;
            begin %= n;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[(begin + i) % n] << " ";
    }
}