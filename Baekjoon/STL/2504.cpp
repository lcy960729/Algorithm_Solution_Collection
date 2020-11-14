#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    string str;
    cin >> str;

    stack<int> st;

    st.push(-str[0]);

    for (int i = 1, top = 0; i < str.length(); i++)
    {
        top = st.top();
        if (str[i] == '(' || str[i] == '[')
        {
            st.push(-str[i]);
        }
        else if ((-top == '(' && str[i] == ')') || (-top == '[' && str[i] == ']'))
        {
            st.pop();
            int temp = (str[i] == ')') ? 2 : 3;
            if (!st.empty() && st.top() >= 0)
            {
                temp += st.top();
                st.pop();
            }
            st.push(temp);
        }
        else if (top >= 0 && (str[i] == ')' || str[i] == ']'))
        {
            st.pop();
            if (!st.empty() && -st.top() == (str[i] == ')' ? '(' : '['))
            {
                st.pop();
                int temp = top * (str[i] == ')' ? 2 : 3);
                while (!st.empty() && st.top() >= 0)
                {
                    temp += st.top();
                    st.pop();
                }
                st.push(temp);
            }
            else
            {
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    if (st.size() == 1 && st.top() > 0)
    {
        cout << st.top() << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}