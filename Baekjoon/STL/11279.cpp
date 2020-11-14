#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int data;
        cin >> data;

        if (data == 0){
            if (!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }else{
                cout << "0" << "\n";
            }
        }else{
            pq.push(data);
        }
    }
}