#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];
int memo[1001];
int N;

int dp(int n){
    int &memoValue = memo[n];
    
    if (N-1 == n){
        return 1;
    }

    if (memoValue != -1){
        return memoValue;
    }

    int maxvalue = 0;
    for (int i = n+1; i < N; i++){
        if (arr[i] <= arr[n])
            continue;

        maxvalue = max(maxvalue, dp(i));
    }
    
    memoValue = maxvalue + 1;
    return memoValue;
}

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
        memo[i] = -1;
    }

    int result = -1;
    for (int i = 0; i < N; i++){
        result = max(result, dp(i));
    }

    cout << result;
}