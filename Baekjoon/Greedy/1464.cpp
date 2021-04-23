#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, ans;
    cin >> str;

    ans = str[0];
    for (int i = 1; i < str.length(); ++i) {
        if (str[i-1] >= str[i] && ans[0] >= str[i]){
            ans = str[i] + ans;
        }else{
            ans += str[i];
        }
    }

    cout << ans << '\n';
}