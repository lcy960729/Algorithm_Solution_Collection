#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

long long dc(int a, int b)
{
    if (a == b)
        return arr[a];

    int mid = a + b >> 1;

    long long ret = 0;
    ret = max(dc(a, mid), dc(mid + 1, b));

    int l = mid;
    int r = mid;

    int height = 0;
    height = min(arr[r], arr[l]);

    while (a != l || b != r)
    {
        if (a == l){
            r++;
        }else if ( b==r ){
            l--;
        }
        else if (arr[l - 1] > arr[r + 1]){
            l--;
        }else 
        {
            r++;
        }

        height = min({arr[r], arr[l], height});
        
        ret = max(ret, 1LL* height * (r-l+1));
    }

    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << dc(0, n-1);
}