#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        string data;
        cin >> data;

        bool check = false;
        for (int j = 0; j < data.length(); j++)
        {
            if (data[j] == '(')
                st.push(data[j]);
            else {
                if (st.empty()){
                    cout << "NO" << "\n";
                    check = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }

        if ( !check){
            if (st.empty()){
                cout << "YES" << "\n";
            }else {
                cout << "NO" << "\n";
            }
        }

        while(!st.empty()){
            st.pop();
        }
    }
}