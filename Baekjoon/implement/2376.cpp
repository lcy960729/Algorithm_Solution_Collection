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

struct Node {
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    int leafIndex = -1;

    ~Node() {
        free(this);
    }
};

vector<Node *> nodes;

void dfs(Node *cur, Node *pre, int e, int cnt) {
    if (cur->leafIndex == e) {
        cout << cnt << '\n';
        return;
    }

    if (cur->left && cur->left != pre)
        dfs(cur->left, cur, e, cnt + 1);

    if (cur->right && cur->right != pre)
        dfs(cur->right, cur, e, cnt + 1);

    if (cur->parent && cur->parent != pre)
        dfs(cur->parent, cur, e, cnt + 1);
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

    Node *root = new Node();

    root->left = new Node();
    root->left->parent = root;
    root->left->leafIndex = 1;

    nodes.push_back(root->left);

    Node *cur = root->left;
    for (int i = 0; i < N - 1; ++i) {
        int dist;
        cin >> dist;

        cur = cur->parent;
        dist--;

        for (int j = 0; j < dist; ++j) {
            if (cur->left && !cur->right) {
                cur->right = new Node();
                cur->right->parent = cur;

                cur = cur->right;
            } else if (!cur->left && !cur->right) {
                cur->left = new Node();
                cur->left->parent = cur;

                cur = cur->left;
            } else if (cur->parent) {
                cur = cur->parent;
            } else if (!cur->parent){
                cur->parent = new Node();
                cur->parent->left = cur;

                cur = cur->parent;
            }
        }

        nodes.push_back(cur);
        cur->leafIndex = i + 2;
    }

    while (cur->parent) {
        cur = cur->parent;
    }

    int s, e;
    cin >> s >> e;

    dfs(nodes[s - 1],
        nullptr, e, 0);
}