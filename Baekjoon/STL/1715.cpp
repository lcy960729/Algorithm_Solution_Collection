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

    if (n==1){
        cout << 0 << "\n";
        return 0;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++){
        int data;
        cin >> data;

        pq.push(data);
    }

    int ret = 0;
    while (pq.size() > 1){
        int val=0;
        val += pq.top();
        pq.pop();
        val += pq.top();
        pq.pop();

        pq.push(val);
        ret += val;
    }

    cout << ret << "\n";
}