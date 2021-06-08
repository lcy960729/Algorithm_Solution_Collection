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

struct Line {
    int sx, sy, ex, ey;

    void sort() {
        if (sx > ex) swap(sx, ex);
        if (sy > ey) swap(ey, ey);
    }
};

struct Point {
    int x, y;
};

bool cmpX(Point &lhs, Point &rhs) {
    if (lhs.x == rhs.x) {
        return lhs.y < rhs.y;
    }

    return lhs.x < rhs.x;
}

bool cmpY(Point &lhs, Point &rhs) {
    if (lhs.y == rhs.y) {
        return lhs.x < rhs.x;
    }

    return lhs.y < rhs.y;
}

vector<Line> horizontal, vertical;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int preX, preY;
    cin >> preX >> preY;

    for (int i = 1; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        Line line = {preX, preY, x, y};
        line.sort();

        if (preX == x)
            vertical.push_back(line);
        else
            horizontal.push_back(line);

        preX = x;
        preY = y;
    }

    vector<Point> sortedX, sortedY;
    for (int i = 0; i < vertical.size(); ++i) {
        for (int j = 0; j < horizontal.size(); ++j) {
            if (vertical[i].sx < horizontal[j].sx) continue;
            if (vertical[i].sx > horizontal[j].ex) continue;
            if (vertical[i].sy > horizontal[j].sy) continue;
            if (vertical[i].ey < horizontal[j].sy) continue;

            sortedX.push_back({vertical[i].sx, horizontal[j].sy});
            sortedY.push_back({vertical[i].sx, horizontal[j].sy});
        }
    }

    sort(sortedX.begin(), sortedX.end(), cmpX);
    sort(sortedY.begin(), sortedY.end(), cmpY);

    for (int i = 0; i < sortedX.size(); ++i) {

    }
}
// TODO 지금 능지 떨어져서 못풀겠음.