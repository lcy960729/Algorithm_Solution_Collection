#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

pair<int, int> arr[101];
int memo[100001][101];
int maxWeight;
int N;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if (p1.second == p2.second){
        return p1.first < p2.first;
    }
    else{
        return p1.second > p2.second;
    }
}

int dp(int n, int top)
{
    if (n == 0){
        return 0;
    }

    int &memoValue = memo[n][top];
    if (memoValue != -1){
        return memoValue;
    }

    int ret = 0;
    for (int i = top; i < N; i++){
        int weight = arr[i].first;
        int price = arr[i].second;
        
        if (n >= weight){
            ret = max({ret,  price + dp(n-weight, i+1)});
            //cout << n << " : " << weight << " : " << ret << " \n";
        }
    }

    memoValue = ret;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    memset(arr, 0, sizeof(arr));
    memset(memo, -1, sizeof(memo));

    cin >> N;
    cin >> maxWeight;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr, arr+N, cmp);

    cout << dp(maxWeight, 0);
}