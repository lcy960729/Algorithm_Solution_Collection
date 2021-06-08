#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int N;
vector<vector<int>> g(100001, vector<int>());
vector<bool> group(100001, false);

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int M;
        cin >> M;

        for (int j = 0; j < M; ++j) {
            int t;
            cin >> t;

            g[i].push_back(t);
        }
    }

    while (true) {
        bool check = true;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;

            for (auto next : g[i]) {
                if (group[next] == group[i]) cnt++;
            }

            if (cnt >= 2) {
                group[i] = !group[i];
                check = false;
            }
        }

        if (check) break;
    }

    vector<int> ans[2];
    for (int i = 1; i <= N; ++i) {
        if (group[i]) ans[0].push_back(i);
        else ans[1].push_back(i);
    }

    for (int i = 0; i < 2; ++i) {
        cout << ans[i].size() << ' ';
        for (auto a : ans[i]) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}

// 원숭이들을 한쪽에 몰아두고 적대 관계가 2마리 이상인 원숭이를 반대편으로 옮긴다.
// 최대 원수를 3마리까지 가질 수 있으므로 총 간선은 3N(중복 제거하면 3N/2)개가 생길 수 있다.
// 여기서 이후 옮겨진 원숭이들을 처리하는 부분이 선형 시간에 끝나게 되는데
// 1번 원숭이가 2번,3번, 4번과 적대 관계이고 같은 우리에 있을때, 1번 원숭이를 반대편으로 옮기게 되면
// 1번 원숭이는 같은 우리에 있는 적대 관계 수가 -3이 되며 2,3,4,번 원숭이들 또한 -1식 줄어 들게 된다.
// 이렇게 -1식 줄어드는 원숭이는 총 3번(N을 3번 == 3N)을 하게되면 모두 -3을 만들 수 있다.