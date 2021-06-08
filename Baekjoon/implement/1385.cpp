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

struct Node {
    int level, index;
    bool isVertex;
};

Node nodes[2000001];
int g[2000001][6];
int visited[2000001] = {};

void setLevel() {
    nodes[0] = {0, 0, true};
    nodes[1] = {0, 0, true};

    int id = 2;
    int depth = 1;

    while (id <= 1000000) {
        for (int j = 0; j < depth * 6; ++j, ++id) {
            nodes[id] = {depth, j, (j % depth) == (depth - 1)};
        };

        depth++;
    }
}

int getStartIndex(int level) {
    if (level == 0) return 1;

    return 3 * pow(level, 2) - 3 * level + 2;
}

int getNextIndex(int level, int index, int diff) {
    if (level == 0) return 1;

    int ret = getStartIndex(level) + (index + diff);

    if (index + diff < 0) {
        ret += (6 * level);
    } else if (index + diff >= 6 * level) {
        ret -= (6 * level);
    }
    return ret;
}

void makeGraph() {
    for (int i = 0; i < 6; ++i) {
        g[0][i] = 0;
        g[1][i] = i + 2;
    }

    for (int i = 2; i <= 1000000; ++i) {
        auto &[level, id, isVertex] = nodes[i];

        int dir = id / level;

        int t[6] = {};
        if (isVertex) {
            if (dir == 0) {
                t[0] = getNextIndex(level + 1, id, level - id);
                t[1] = getNextIndex(level + 1, id, 2);
                t[2] = getNextIndex(level, id, 1);
                t[3] = getNextIndex(level - 1, id, (level - 2) - id);
                t[4] = getNextIndex(level, id, -1);
                t[5] = getNextIndex(level + 1, id, 0);
            } else if (dir == 1) {
                t[0] = getNextIndex(level + 1, id, 1);
                t[1] = getNextIndex(level + 1, id, level + (level + 1) - id);
                t[2] = getNextIndex(level + 1, id, 3);
                t[3] = getNextIndex(level, id, 1);
                t[4] = getNextIndex(level - 1, id, (level - 2) + (level - 1) - id);
                t[5] = getNextIndex(level, id, -1);
            } else if (dir == 2) {
                t[0] = getNextIndex(level, id, -1);
                t[1] = getNextIndex(level + 1, id, 2);
                t[2] = getNextIndex(level + 1, id, level + 2 * (level + 1) - id);
                t[3] = getNextIndex(level + 1, id, 4);
                t[4] = getNextIndex(level, id, 1);
                t[5] = getNextIndex(level - 1, id, (level - 2) + 2 * (level - 1) - id);
            } else if (dir == 3) {
                t[0] = getNextIndex(level - 1, id, (level - 2) + 3 * (level - 1) - id);
                t[1] = getNextIndex(level, id, -1);
                t[2] = getNextIndex(level + 1, id, 3);
                t[3] = getNextIndex(level + 1, id, level + 3 * (level + 1) - id);
                t[4] = getNextIndex(level + 1, id, 5);
                t[5] = getNextIndex(level, id, 1);
            } else if (dir == 4) {
                t[0] = getNextIndex(level, id, 1);
                t[1] = getNextIndex(level - 1, id, (level - 2) + 4 * (level - 1) - id);
                t[2] = getNextIndex(level, id, -1);
                t[3] = getNextIndex(level + 1, id, 4);
                t[4] = getNextIndex(level + 1, id, level + 4 * (level + 1) - id);
                t[5] = getNextIndex(level + 1, id, 6);
            } else if (dir == 5) {
                t[0] = getNextIndex(level + 1, id, -id);
                t[1] = getNextIndex(level, id, -id);
                t[2] = getNextIndex(level - 1, id, -id - 1);
                t[3] = getNextIndex(level, id, -1);
                t[4] = getNextIndex(level + 1, id, 5);
                t[5] = getNextIndex(level + 1, id, level + 5 * (level + 1) - id);
            }
        } else {
            if (dir == 0) {
                t[0] = getNextIndex(level + 1, id, 1);
                t[1] = getNextIndex(level, id, 1);
                t[2] = getNextIndex(level - 1, id, 0);
                t[3] = getNextIndex(level - 1, id, -1);
                t[4] = getNextIndex(level, id, -1);
                t[5] = getNextIndex(level + 1, id, 0);
            } else if (dir == 1) {
                t[0] = getNextIndex(level + 1, id, 1);
                t[1] = getNextIndex(level + 1, id, 2);
                t[2] = getNextIndex(level, id, 1);
                t[3] = getNextIndex(level - 1, id, -1);
                t[4] = getNextIndex(level - 1, id, -2);
                t[5] = getNextIndex(level, id, -1);
            } else if (dir == 2) {
                t[0] = getNextIndex(level, id, -1);
                t[1] = getNextIndex(level + 1, id, 2);
                t[2] = getNextIndex(level + 1, id, 3);
                t[3] = getNextIndex(level, id, 1);
                t[4] = getNextIndex(level - 1, id, -2);
                t[5] = getNextIndex(level - 1, id, -3);
            } else if (dir == 3) {
                t[0] = getNextIndex(level - 1, id, -4);
                t[1] = getNextIndex(level, id, -1);
                t[2] = getNextIndex(level + 1, id, 3);
                t[3] = getNextIndex(level + 1, id, 4);
                t[4] = getNextIndex(level, id, 1);
                t[5] = getNextIndex(level - 1, id, -3);
            } else if (dir == 4) {
                t[0] = getNextIndex(level - 1, id, -4);
                t[1] = getNextIndex(level - 1, id, -5);
                t[2] = getNextIndex(level, id, -1);
                t[3] = getNextIndex(level + 1, id, 4);
                t[4] = getNextIndex(level + 1, id, 5);
                t[5] = getNextIndex(level, id, 1);
            } else if (dir == 5) {
                t[0] = getNextIndex(level, id, 1);
                t[1] = getNextIndex(level - 1, id, -5);
                t[2] = getNextIndex(level - 1, id, -6);
                t[3] = getNextIndex(level, id, -1);
                t[4] = getNextIndex(level + 1, id, 5);
                t[5] = getNextIndex(level + 1, id, 6);
            }
        }

        for (int j = 0; j < 6; ++j) {
            g[i][j] = t[j];
        }
    }
}

int path[2000001] = {};
void print(int cur, int s) {
    if (s == cur) {
        cout << cur << ' ';
        return;
    }

    print(path[cur], s);
    cout << cur << ' ';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    setLevel();
    makeGraph();

    memset(visited, -1, sizeof(visited));

    queue<int> q;
    q.push(a);
    visited[a] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == b) {
            print(b, a);
            break;
        }

        for (auto &next : g[cur]) {
            if (next > 1000000 || visited[next] != -1) continue;

            q.push(next);
            visited[next] = visited[cur] + 1;
            path[next] = cur;
        }
    }
}