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

    int n;
    cin >> n;

    queue<int> que;

    for (int i = 0; i < n; i++){
        string inst;
        cin >> inst;

        if (inst.compare("push") == 0){
            int data;
            cin >> data;
            que.push(data);
        }else if (inst.compare("pop") == 0){
            if (!que.empty()){
                cout << que.front() << "\n";
                que.pop();
            }else {
                cout << -1 << "\n";
            }
        }else if (inst.compare("size") == 0){
            cout << que.size() << "\n";
        }else if (inst.compare("empty") == 0){
            if (!que.empty()){
                cout << 0 << "\n";
            }else {
                cout << 1 << "\n";
            }
        }else if (inst.compare("front") == 0){
            if (!que.empty()){
                cout << que.front() << "\n";
            }else {
                cout << -1 << "\n";
            }
        }else if (inst.compare("back") == 0){
            if (!que.empty()){
                cout << que.back() << "\n";
            }else {
                cout << -1 << "\n";
            }
        }
    }
}