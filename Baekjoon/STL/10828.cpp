#include<iostream>
#include<algorithm>
#include<stack>

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

    stack<int> st;

    for (int i = 0; i < n; i++){
        string inst;
        cin >> inst;

        if (inst.compare("push") == 0){
            int data;
            cin >> data;
            st.push(data);
        }else if (inst.compare("pop") == 0){
            if (!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }else {
                cout << -1 << "\n";
            }
        }else if (inst.compare("size") == 0){
            cout << st.size() << "\n";
        }else if (inst.compare("empty") == 0){
            if (!st.empty()){
                cout << 0 << "\n";
            }else {
                cout << 1 << "\n";
            }
        }else if (inst.compare("top") == 0){
            if (!st.empty()){
                cout << st.top() << "\n";
            }else {
                cout << -1 << "\n";
            }
        }
    }
}