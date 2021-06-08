#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

const double eps = 1e-6;

struct Point {
    string name;
    int x = -1, y = -1;
};

int A, B, C;
initializer_list<LNode> N;

map<string, int> gasStations;
map<string, Point> points;

int K;
vector<pair<int, string>> queries;

int calcDist(Point *cur, Point *next) {
    return abs(cur->x - next->x) + abs(cur->y - next->y);
}

vector<string> split(string s, string parser) {
    vector<string> ret;

    int pre = 0;
    int cur = s.find(parser, pre);

    while (cur != string::npos) {
        string token = s.substr(pre, cur - pre);

        if (!token.empty())
            ret.push_back(token);

        pre = cur + parser.size();
        cur = s.find(parser, pre);
    }

    string token = s.substr(pre);

    if (!token.empty())
        ret.push_back(token);

    return ret;
}

void input() {
    cin >> A >> B >> C >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string s;
        getline(cin, s);

        vector<string> tokens = split(s, " ");

        Point point;
        for (auto &token : tokens) {
            if (('\'' == token[0]) || ('A' <= token[0] && token[0] <= 'Z') || ('a' <= token[0] && token[0] <= 'z'))
                point.name += token + " ";
            else if (('0' <= token[0] && token[0] <= '9')) {
                if (point.x == -1)
                    point.x = stoi(token);
                else
                    point.y = stoi(token);
            }
        }
        point.name.pop_back();
        points[point.name] = point;
    }


    for (int i = 0; i < 3; ++i) {
        string s;
        getline(cin, s);

        vector<string> tokens = split(s, " ");

        string name;
        int price;
        for (auto &token : tokens) {
            if (('\'' == token[0]) || ('A' <= token[0] && token[0] <= 'Z') || ('a' <= token[0] && token[0] <= 'z'))
                name += token + " ";
            else if (('0' <= token[0] && token[0] <= '9')) {
                price = stoi(token);
            }
        }
        name.pop_back();

        gasStations.insert({name, price});
    }

    cin >> K;
    cin.ignore();

    queries.assign(K, {});

    for (auto &query : queries) {
        string s;
        getline(cin, s);

        s.pop_back();

        string op0 = "Go to ";
        string op1 = "Pickup a passenger going to ";

        if (s.find(op0) != string::npos) {
            query.first = 0;
            query.second = s.substr(op0.size());
        } else {
            query.first = 1;
            query.second = s.substr(op1.size());
        }
    }
}

bool isGasStation(Point *point) {
    return gasStations.find(point->name) != gasStations.end();
}

void solve() {
    // Taxi Garage 주유소 x
    double remainingDist = A * C;
    int numOfCustomer = 0;
    int money = 0;

    map<string, vector<int>> customers;

    Point *curPoint = &points["Taxi Garage"];

    for (const auto &query : queries) {
        if (query.first == 0) {
            Point *nextPoint = &points[query.second];

            int dist = calcDist(curPoint, nextPoint);

            remainingDist -= dist;
            if (remainingDist < 0) {
                cout << "OUT OF GAS";
                return;
            }

            curPoint = nextPoint;

            for (auto &customer : customers) {
                for (auto &totalDist : customer.second) {
                    totalDist += dist;
                }
            }

            if (customers.find(curPoint->name) != customers.end()) {
                for (const auto &totalDist : customers[curPoint->name]) {
                    money += totalDist * B;
                    numOfCustomer--;
                }
                customers.erase(curPoint->name);
            }

            if (isGasStation(curPoint)) {
                // (A*C) = 최대 충전시 갈 수 있는 거리
                // requiredDist 충전해야할 거리
                double requiredDist = (A * C) - remainingDist;
                double pricePerGallon = gasStations[curPoint->name];

                // 구매할 기름 전체 가격
                // 필요한 거리를 '1갤런당 갈 수 있는 거리'로 나눔.
                // 결과 값은 몇 갤런이 필요한지 나올꺼고 1갤런당 가격을 곱해줌
                int totalPrice = (requiredDist * pricePerGallon) / C + 1e-12;

                // 돈이 딱 맞거나 많으면 필요한 거리만큼 추가해주고 가격만큼 뺌
                if (money >= totalPrice) {
                    remainingDist += requiredDist;
                    money -= totalPrice;
                } else {
                    // 돈이 부족하면 남은 갈 수 있는 거리(remainingDist)에 현재 있는 돈과 1갤런당 가격을 나눠서
                    // 살 수 있는 갤런을 구한후 1 갤런 당 갈 수 있는 거리를 곱해줌
                    requiredDist = money * C / pricePerGallon;
                    remainingDist += requiredDist;

                    totalPrice = requiredDist * pricePerGallon / C;
                    money -= totalPrice;
                }
            }
        } else {
            if (numOfCustomer >= 3) {
                cout << "CAPACITY FULL";
                return;
            }

            Point *destination = &points[query.second];

            customers[destination->name].push_back(0);
            numOfCustomer++;
        }

//        cout << remainingDist << '/' << money << '\n';
    }

    if (curPoint->name != "Taxi Garage")
        cout << "NOT IN GARAGE";
    else if (curPoint->name == "Taxi Garage" && numOfCustomer > 0)
        cout << "REMAINING PASSENGER";
    else
        cout << money;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    cout << '\n';
}