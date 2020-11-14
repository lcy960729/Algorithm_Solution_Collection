#include<iostream>
#include<algorithm>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    pair<int, int> m[100000];

    for  (int i = 0; i < n; i++){
            cin >> m[i].first;
            cin >> m[i].second;
    }
    
    sort(m, m+n, comp);

    int index = 0;
    int ret = 1;
    
    for (int i = 1; i < n; i++){
        if (m[index].second <= m[i].first){
            index = i;
            ret++;
        }
    }
     cout << ret;
}