#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <list>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

//A, D => D에서 A로 올라감 \
//B, C => C에서 B로 올라감 /

struct Node {
    int id;
    int x, y;
    Node *a, *b, *c, *d;
};

bool sum_cmp(const Node &lhs, const Node &rhs) {
    int lhs_sum = lhs.x + lhs.y;
    int rhs_sum = rhs.x + rhs.y;

    if (lhs_sum == rhs_sum) {
        return lhs.x < rhs.x;
    }

    return lhs_sum < rhs_sum;
}


bool diff_cmp(const Node &lhs, const Node &rhs) {
    int lhs_diff = lhs.x - lhs.y;
    int rhs_diff = rhs.x - rhs.y;

    if (lhs_diff == rhs_diff) {
        return lhs.x < rhs.x;
    }

    return lhs_diff < rhs_diff;
}

void delNode(Node *p) {
    if (p->a) p->a->d = p->d;
    if (p->d) p->d->a = p->a;
    if (p->b) p->b->c = p->c;
    if (p->c) p->c->b = p->b;
}

vector<Node> flowers;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        flowers.push_back({i, x, y});
    }

    vector<Node> sum_flowers(flowers);
    sort(sum_flowers.begin(), sum_flowers.end(), sum_cmp);
    for (int i = 0; i < N - 1; ++i) {
        Node &cur = flowers[sum_flowers[i].id];
        Node &next = flowers[sum_flowers[i + 1].id];

        if ((cur.x + cur.y) == (next.x + next.y)) {
            cur.b = &next;
            next.c = &cur;
        }
    }

    vector<Node> diff_flowers(flowers);
    sort(diff_flowers.begin(), diff_flowers.end(), diff_cmp);
    for (int i = 0; i < N - 1; ++i) {
        Node &cur = flowers[diff_flowers[i].id];
        Node &next = flowers[diff_flowers[i + 1].id];

        if ((cur.x - cur.y) == (next.x - next.y)) {
            cur.a = &next;
            next.d = &cur;
        }
    }

    Node *frog = &flowers[0];

    for (char c : s) {
        if (c == 'A') {
            if (frog->a) {
                delNode(frog);
                frog = frog->a;
            }
        } else if (c == 'B') {
            if (frog->b) {
                delNode(frog);
                frog = frog->b;
            }
        } else if (c == 'C') {
            if (frog->c) {
                delNode(frog);
                frog = frog->c;
            }
        } else if (c == 'D') {
            if (frog->d) {
                delNode(frog);
                frog = frog->d;
            }
        }
    }

    cout << frog->x << ' ' << frog->y << '\n';
}