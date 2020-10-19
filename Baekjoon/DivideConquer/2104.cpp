#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

long long dc(int begin, int end)
{
    if (begin == end)
        return (long long)arr[begin] * arr[end];

    int mid = begin + end >> 1;

    long long ret = max(dc(begin, mid), dc(mid + 1, end));

    int left = mid;
    int right = mid;

    int height = arr[mid];
    long long width = arr[mid];

    while (begin != left || end != right)
    {
        if (begin == left){
            right++;
            width += arr[right];
        }else if (end == right){
            left--;
            width += arr[left];
        }
        else if (arr[left - 1] > arr[right + 1]){
            left--;
            width += arr[left];            
        }else 
        {
            right++;
            width += arr[right];
        }

        height = min({arr[right], arr[left], height});
        
        ret = max(ret, 1LL* height * width);
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