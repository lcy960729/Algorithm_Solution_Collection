#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    queue<int> que;

    for (int i = 1; i <= n; i++){
        que.push(i);
    }

    while(que.size() != 1){
        que.pop();
        int temp = que.front();
        que.pop();
        que.push(temp);
    }

    cout << que.front();
}