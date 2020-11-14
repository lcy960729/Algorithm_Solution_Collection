//
// Created by CY on 2020-09-25.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N, M;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pii > chicken;
    vector<pii > house;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int mapInfo;
            cin >> mapInfo;

            if (mapInfo == 1) {
                house.emplace_back(i, j);
            } else if (mapInfo == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }

    vector<int> pick(chicken.size());
    for (int i = 0; i < chicken.size() - M; ++i) {
        pick.push_back(0);
    }
    for (int i = 0; i < M; ++i) {
        pick.push_back(1);
    }

    int answer = 1e9;
    do {
        int sum = 0;
        for (auto &i : house) {
            int houseY = i.first;
            int houseX = i.second;

            int dist = 1e9;
            for (int j = 0; j < pick.size(); ++j) {
                if (pick[j]) {
                    int chickenY = chicken[j].first;
                    int chickenX = chicken[j].second;

                    dist = min(dist, abs(houseX - chickenX) + abs(houseY - chickenY));
                }
            }
            sum += dist;
        }
        answer = min(answer, sum);
    } while (next_permutation(pick.begin(), pick.end()));

    cout << answer << "\n";
}