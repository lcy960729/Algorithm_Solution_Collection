#include<iostream>
#include<algorithm>

using namespace std;

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;

    int crain[50];
    for (int i = 0; i < n; i++){
        cin >> crain[i];
    }

    int m;
    cin >> m;

    int box[10000];
    for (int i = 0; i < m; i++){
        cin >> box[i];
    }

    int ret = 0;
    int boxCount = 0;
    int crainStartIndex[50];
    sort(crain, crain+n, greater<int>());
    sort(box, box+m, greater<int>());

    if  (crain[0] < box[0]){
        cout << -1;
        return 0;
    }

    while (m != boxCount){
        for (int i = 0 ; i < n; i++){
            for (int &j = crainStartIndex[i]; j < m; j++){
                if (crain[i] >= box[j]){
                    boxCount++;
                    box[j] = 1e9;
                    break;
                }
            }
        }
        ret++;
    }

    cout << ret;
}