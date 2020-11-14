//
// Created by lcy96 on 2020-09-08.
//

//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

#define pii pair<int, int>
#define ll long long

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int k;
    cin >> k;

    stack<int> st;

    for (int i = 0; i < k; i++){
        int num;
        cin >> num;

        if (num==0){
            st.pop();
        }else{
            st.push(num);
        }
    }

    long long sum = 0;
    while(!st.empty()){
        sum+=st.top();
        st.pop();
    }
    cout << sum;
}