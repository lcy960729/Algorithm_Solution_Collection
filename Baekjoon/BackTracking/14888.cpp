//
// Created by CY on 2020-09-28.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
int arr[12];
int op[4];

int minValue = 1e9;
int maxValue = -1e9;

int selected[4] = {};

void dfs(int cnt, int result){
    if (selected[0] == op[0] && selected[1] == op[1] && selected[2] == op[2] && selected[3] == op[3]){
        minValue = min(minValue, result);
        maxValue = max(maxValue, result);

        return;
    }

    for (int i = 0; i < 4; ++i){
        if (selected[i] == op[i])
            continue;

        selected[i]++;
        if (i == 0){
            dfs(cnt+1, result+arr[cnt+1]);
        }else if (i == 1){
            dfs(cnt+1, result-arr[cnt+1]);
        }else if (i == 2){
            dfs(cnt+1, result*arr[cnt+1]);
        }else if (i == 3){
            dfs(cnt+1, result/arr[cnt+1]);
        }
        selected[i]--;
    }

}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }

    for(int i = 0; i < 4; ++i){
        cin >> op[i];
    }

    dfs(0, arr[0]);
    cout << maxValue << "\n" << minValue;
}
