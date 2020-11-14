#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int t;
    int a;
    int h;
} RoomInfo;

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

    int arr[100001];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long left = 0, mid = 0, right = 1e9+1;

    while (left + 1 < right)
    {
        mid = (left + right) / 2 ;

        int sum = 1;
        for (int i = 0; i < n; i++){
            sum += ((arr[i]-1) / mid) -1;
        }

        if (sum > 0) //남는것들이 있다는 것
            left = mid;
        else
            right = mid;
    }
    
    cout << right << "\n";
}