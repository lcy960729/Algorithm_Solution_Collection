//
// Created by CY on 2020-09-10.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;

int visited[1001][1001];
int degreeCnt[1001];

vector<int> node[1001];

void dfs(int now) {
    for (int next: node[now]) {
        while(visited[now][next]) {
            visited[now][next]--;
            visited[next][now]--;

            dfs(next);
        }
    }
    cout << now << " ";
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int m;
            cin >> m;

            if (m != 0) {
                node[i].push_back(j);

                visited[i][j] = m;

                degreeCnt[i] += m;
                degreeCnt[j] += m;
            }
        }
    }

    bool isEulerianCircuit = true;
    for (int i = 1; i <= N; i++){
        degreeCnt[i] /= 2;
        if (degreeCnt[i] % 2 == 1){
            isEulerianCircuit = false;
            break;
        }
    }

    if (isEulerianCircuit) {
        dfs(1);
    }else{
        cout << -1;
    }
}