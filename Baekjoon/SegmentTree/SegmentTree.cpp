//
// Created by LeeChanYoung on 2021/01/31.
//
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
int sz = 10;
vector<int> seg;

void update(int id) {
    if (id == 0) return;
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void update(int id, int val) {
    id += sz;
    seg[id] = val;
    update(id / 2);
}

int ask(int l, int r, int id = 1, int nodeL = 0, int nodeR = sz - 1) {
    if (r < nodeL || nodeR < l) return 0;
    if (l <= nodeL && nodeR <= r) return seg[id];
    int mid = nodeL + nodeR / 2;
    return ask(l, r, id * 2, nodeL, mid) + ask(l, r, id * 2 + 1, mid + 1, nodeR);
}

//l~r까지 합 구하기
int ask(int l, int r) {
    l += sz;
    r += sz;
    int ret = 0;
    while (l <= r) {
        if (l % 2 == 1) ret += seg[l++];
        if (r % 2 == 0) ret += seg[r--];
        l /= 2;
        r /= 2;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}
