#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    pair<int, int> m[200000];
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        cin >> m[i].first;
        cin >> m[i].second;
    }

    sort(m, m+n, cmp);

    pq.push(m[0].second);

    for (int i = 1; i < n; i++){
        if (pq.top() > m[i].first){
            pq.push(m[i].second);
        }else{
            pq.pop();
            pq.push(m[i].second);
        }
    }

    cout << pq.size();
}