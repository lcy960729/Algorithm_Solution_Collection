#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T, N, K;

vector<int> node[100001];
int p[100001];
bool visited[100001];

int setSize = 0;

long long dfs(int id, long long maxCure){
    long long people = p[id];
    
    for (int t : node[id]){
        if (visited[t])
            continue;

        visited[t] = true;

        people += dfs(t, maxCure);

        if (setSize > K)
            return 0;

        cout << id << " : " << t <<  " : " << people << " : " << setSize << endl;

        if (people > maxCure){
            setSize++;
            people = p[id];
        }
    }

    return people;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> N >> K;

        for (int j = 1; j <= N; j++){
            cin >> p[j];
        }

        for (int j = 0; j < N-1; j++){
            int from, to;
            cin >> from >> to;
            node[from].push_back(to);
            node[to].push_back(from);
        }

        long long left = 0, mid = 0, right = 1e9*1e5;

        while( left+1 < right){
            mid = (left + right) / 2;
            
            setSize = 0;
            memset(visited, false, sizeof(visited));

            visited[1] = true;
            dfs(1, mid);

            cout << "cure : " << mid << endl;
            cout << "setSize : " << setSize << endl;
            cout << endl;

            if (setSize > K){
                left = mid;
            }else{
                right = mid;
            }
        }

        cout << right;
    }
}