#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

struct Line {
    ll sy, sx, ey, ex;
    int dir;

    bool isVertical() {
        return (dir == 1 || dir == 3);
    }
};

//lhs 기준, rhs가 비교
ll crash(Line lhs, Line rhs) {
    if ((lhs.isVertical())) {
        if (rhs.isVertical()) { // 기준 세로, 비교 세로
            if (lhs.sx != rhs.sx) return -1;

            if (lhs.sy <= rhs.sy && lhs.ey <= rhs.sy) {
                // dir 3
                return lhs.ey - rhs.sy;
            } else if (rhs.sy <= lhs.sy && rhs.ey <= lhs.sy) {
                // dir 0
                return rhs.ey - lhs.sy;
            }
        } else { // 기준 세로, 비교 가로
            if (lhs.sy > rhs.sy || rhs.sy > lhs.ey) return -1;

            if (rhs.sx <= lhs.sx && lhs.sx <= rhs.ex) {
                if (rhs.dir == 0) {
                    return rhs.ex - lhs.sx;
                } else if (rhs.dir == 2) {
                    return lhs.sx - rhs.sx;
                }
            }
        }
    } else {
        if (rhs.isVertical()) { // 기준 가로, 비교 세로
            if (rhs.sy > lhs.sy || lhs.sy > rhs.ey) return -1;

            if (lhs.sx <= rhs.sx && rhs.sx <= lhs.ex) {
                if (rhs.dir == 1) {
                    return rhs.ey - lhs.sy;
                } else if (rhs.dir == 3) {
                    return lhs.sy - rhs.sy;
                }
            }
        } else { // 기준 가로, 비교 가로
            if (lhs.sy != rhs.sy)
                return -1;

            if (lhs.sx <= rhs.sx && rhs.sx <= lhs.ex) {
                // dir 2
                return lhs.ex - rhs.sx;
            } else if (rhs.sx <= lhs.sx && lhs.sx <= rhs.ex) {
                // dir 0
                return rhs.ex - lhs.sx;
            }
        }
    }
    return -1;
}

int L;
initializer_list<LNode> N;
vector<pair<ll, int>> dirList;
vector<Line> lines;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> L >> N;

    for (int i = 0; i < N; ++i) {
        ll t;
        char dir;
        cin >> t >> dir;

        dirList.push_back({t, dir == 'L' ? -1 : 1});
    }
    dirList.push_back({2 * L + 1, 0});

    pair<ll, ll> snake = {L, L};
    int snakeDir = 0;

    ll ans = 0;

    lines.push_back({-1, -1, -1, 2 * L + 1, 0});
    lines.push_back({-1, -1, 2 * L + 1, -1, 1});
    lines.push_back({2 * L + 1, -1, 2 * L + 1, 2 * L + 1, 2});
    lines.push_back({-1, 2 * L + 1, 2 * L + 1, 2 * L + 1, 3});

    lines.push_back({snake.first, snake.second, snake.first, snake.second, 0});

    for (const auto &item : dirList) {
        ll ny = snake.first + (dy[snakeDir] * item.first);
        if (ny < 0) {
            ny = -1;
        } else if (ny > 2 * L) {
            ny = 2 * L + 1;
        }

        ll nx = snake.second + (dx[snakeDir] * item.first);
        if (nx < 0) nx = -1;
        else if (nx > 2 * L) nx = 2 * L + 1;

        ll cnt = max(abs(snake.first - ny), abs(snake.second - nx));
        ans += cnt;

        ll sy = snake.first, sx = snake.second, ey = ny, ex = nx;

        if (sy > ey) swap(sy, ey);
        if (sx > ex) swap(sx, ex);

        Line rhs = {sy, sx, ey, ex, snakeDir};

        ll ret = -1;
        for (int i = 0; i < lines.size() - 1; ++i) {
            ll isCrash = crash(lines[i], rhs);

            if (isCrash != -1)
                ret = max(ret, isCrash);
        }

        if (ret != -1) {
            ans -= ret;
            break;
        }

        lines.push_back(rhs);

        snake.first = ny;
        snake.second = nx;

        snakeDir += item.second;
        if (snakeDir < 0) snakeDir += 4;
        snakeDir %= 4;
    }

    cout << ans << '\n';
}