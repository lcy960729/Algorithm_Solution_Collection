#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

typedef struct
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        else
            return p1.second < p2.second;
    }
} cmp;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    multiset<int> bag; 

    int n;
    cin >> n;

    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int weight;
        int price;

        cin >> weight;
        cin >> price;

        pq.push({weight, price});
    }

    for (int i = 0; i < k; i++)
    {
        int weight;
        cin >> weight;

        bag.insert(weight);
    }

    long long ret = 0;
    int count = 0;
    while(!pq.empty() && count < k){
        multiset<int>::iterator iter = bag.lower_bound(pq.top().first);
        
        if (iter != bag.end()){
            ret += pq.top().second;
            bag.erase(iter);
            count++;
        }

        pq.pop();
    }

    cout << ret << "\n";
}