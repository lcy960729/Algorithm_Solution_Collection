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

vector<ll> operand;
vector<char> op;

int parent[200001];

int find(int id) {
    if (parent[id] < 0)
        return id;

    return parent[id] = find(parent[id]);
}

void uni(int a, int b, ll ret) {
    int parentA = find(a);
    int parentB = find(b);

    if (parentA == parentB) return;

    parent[parentA] = min(parent[parentA], parent[parentB]);
    parent[parentB] = parentA;

    operand[parentA] = ret;
}

struct Node {
    int lhsId, rhsId, opId;
    ll ret;

    int getPriority() const {
        return (op[opId] == '*' || op[opId] == '/') ? 1 : 0;
    }

    bool operator<(const Node &n1) const {
        if (ret == n1.ret) {
            if (getPriority() == n1.getPriority()) {
                return lhsId > n1.lhsId;
            }

            return getPriority() < n1.getPriority();
        }

        return ret < n1.ret;
    }
};

ll calc(Node &n1) {
    n1.lhsId = find(n1.lhsId);
    n1.rhsId = find(n1.rhsId);

    if (op[n1.opId] == '+') {
        return operand[n1.lhsId] + operand[n1.rhsId];
    } else if (op[n1.opId] == '-') {
        return operand[n1.lhsId] - operand[n1.rhsId];
    } else if (op[n1.opId] == '*') {
        return operand[n1.lhsId] * operand[n1.rhsId];
    } else if (op[n1.opId] == '/') {
        return operand[n1.lhsId] / operand[n1.rhsId];
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(parent, -1, sizeof(parent));

    string s;
    cin >> s;

    string temp;
    for (char &c : s) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            operand.push_back(stoll(temp));
            op.push_back(c);

            temp.clear();
        } else {
            temp += c;
        }
    }
    operand.push_back(stoll(temp));

    for (int i = 0; i < operand.size(); ++i) {
        parent[i] = -(i + 1);
    }

    priority_queue<Node> pq;
    for (int i = 0; i < op.size(); ++i) {
        Node node = {i, i + 1, i};
        node.ret = calc(node);

        pq.push(node);
    }

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if ((find(node.lhsId) == find(node.rhsId)) || (calc(node) != node.ret))
            continue;

        uni(node.lhsId, node.rhsId, node.ret);

        int preId = find(node.lhsId) - 1;
        if (preId >= 0) {
            preId = (preId);
            int preOpId = -parent[preId] - 1;

            Node pre = {preId, find(node.lhsId), preOpId};
            pre.ret = calc(pre);

            pq.push(pre);
        }

        int nextId = find(-parent[find(node.rhsId)]);
        if (nextId < operand.size()) {
            int nextOpId = nextId - 1;

            Node next = {find(node.rhsId), nextId, nextOpId};
            next.ret = calc(next);

            pq.push(next);
        }
    }

    cout << operand[0] << '\n';
}