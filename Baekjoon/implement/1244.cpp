#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

void boy(int num, vector<bool> &lights) {
    int id = num - 1;

    while (id < lights.size()) {
        lights[id] = !lights[id];
        id += num;
    }
}

void girl(int id, int cnt, vector<bool> &lights) {
    int right = id + cnt;
    int left = id - cnt;

    if (right < 0 || right >= lights.size() || left < 0 || left >= lights.size())
        return;

    if (lights[right] != lights[left])
        return;

    lights[right] = !lights[right];
    lights[left] = !lights[left];

    girl(id, cnt + 1, lights);
}

void girl(int num, vector<bool> &lights) {
    lights[num - 1] = !lights[num - 1];
    girl(num - 1, 1, lights);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> lights(N);
    for (int i = 0; i < N; ++i) {
        int state;
        cin >> state;

        lights[i] = state;
    }

    int S;
    cin >> S;

    for (int i = 0; i < S; ++i) {
        int gender;
        int num;
        cin >> gender >> num;

        if (gender == 1) {
            boy(num, lights);
        } else {
            girl(num, lights);
        }
    }

    for (int i = 0; i < lights.size(); ++i) {
        cout << (lights[i] ? 1 : 0) << ' ';

        if (i % 20 == 19)
            cout << '\n';
    }

    cout << '\n';
}