#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    queue<int> q;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;

        q.push(data);
    }

    int order = 1;
    for (int i = 0; i <= n; i++)
    {
        if (!q.empty() && q.front() == order)
        {
            order++;
        }
        else
        {
            while (!st.empty() && order == st.top())
            {
                st.pop();
                order++;
            }
            if (!q.empty())
                st.push(q.front());
        }

        if (!q.empty())
            q.pop();
    }

    if (q.empty() && st.empty()){
        cout << "Nice" << "\n";
    }else{
        cout << "Sad" << "\n";
    }
}