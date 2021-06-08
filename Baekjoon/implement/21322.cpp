#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

struct Node {
    int y, x;
};

int M;
initializer_list<LNode> N;
vector<vector<int>> board;
vector<vector<Node>> position;
vector<int> numOfRotations;
vector<vector<int>> positionIds;

void fun1(int a, int b) {
    // 이거는 돌리는 함수임
    // 원래 값에 b만큼 더함
    // 근데 b가 어짜피 최대 크기를 넘으면 한바퀴 도는 의미니까 모듈라 해서 저장

    numOfRotations[a] = (numOfRotations[a] + b) % position[a].size();
}

Node getPoint(int y, int x) {
    // 좌료를 가져옴

    // 내가 몇번째 벨트인지 찾고
    int positionId = min({abs(N - 1 - y), abs(N - 1 - x), abs(y - 0), abs(x - 0)});

    // 최대 벨트 크기
    const int mod = position[positionId].size();

    // 현재 위치는 원래 위치 아이디에서 돌린 횟수만큼 빼줌
    int curId = positionIds[y][x] - numOfRotations[positionId];
    // 음수면 mod 더하고
    if (curId < 0)
        curId += mod;

    // 모듈라해서 위치 찾음
    curId %= mod;

    // 위치 반환
    return position[positionId][curId];
}

void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Node p = getPoint(i, j);
            cout << board[p.y][p.x] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void fun2(int c, int d) {
    // 요기는 그냥 4개 시계 방향으로 스왑하는거임

    Node cd = getPoint(c, d);
    Node c1d = getPoint(c + 1, d);
    Node c1d1 = getPoint(c + 1, d + 1);
    Node cd1 = getPoint(c, d + 1);

    int temp = board[cd.y][cd.x];

    board[cd.y][cd.x] = board[c1d.y][c1d.x];
    board[c1d.y][c1d.x] = board[c1d1.y][c1d1.x];
    board[c1d1.y][c1d1.x] = board[cd1.y][cd1.x];
    board[cd1.y][cd1.x] = temp;
}

void fun3(int e, int f) {
    Node p = getPoint(e, f);
    cout << board[p.y][p.x] << '\n';
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    board.assign(N, vector<int>(N));

    for (auto &i : board) {
        for (auto &j : i) {
            cin >> j;
        }
    }

    position.assign(N / 2, vector<Node>());
    numOfRotations.assign(position.size(), 0);
    positionIds.assign(N, vector<int>(N));

    // 이거는 벨트마다 인덱스 저장
    // position은 벨트마다 가지고 있는 좌표들을 저장
    // positionIds 해당 좌표가 가지는 좌표 index를 저장
    for (int i = 0; i < position.size(); ++i) {
        int size = N - 1 - (i * 2);

        int id = 0;
        for (int j = 0; j < size; ++j) {
            position[i].push_back({i, j + i});
            positionIds[i][j + i] = id++;
        }

        for (int j = 0; j < size; ++j) {
            position[i].push_back({j + i, size + i});
            positionIds[j + i][size + i] = id++;
        }

        for (int j = 0; j < size; ++j) {
            position[i].push_back({size + i, size + i - j});
            positionIds[size + i][size + i - j] = id++;
        }

        for (int j = 0; j < size; ++j) {
            position[i].push_back({size + i - j, i});
            positionIds[size + i - j][i] = id++;
        }
    }

    for (int i = 0; i < M; ++i) {
//        print();

        int op, lhs, rhs;
        cin >> op >> lhs >> rhs;

        lhs--;
        if (op != 1) rhs--;

        if (op == 1) {
            fun1(lhs, rhs);
        } else if (op == 2) {
            fun2(lhs, rhs);
        } else if (op == 3) {
            fun3(lhs, rhs);
        }
    }
}