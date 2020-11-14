#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector<int> node[300001];
vector<pair<int, int>> edge;
long long findG(int i)
{
    int size = node[i].size();

    long long numerator = 1;
    for (int i = 0; i < 3; i++)
        numerator *= (size - i);

    long long denominator = 1;
    for (int i = 1; i <= 3; i++)
        denominator *= i;

    return numerator / denominator;
}

long long findD()
{
    long long result = 0;

    for (pair<int, int> e : edge){
        result += (node[e.first].size()-1) * (node[e.second].size()-1);
    }

    return result;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);

        edge.push_back({u, v});
    }

    long long d = 0, g = 0;

    for (int i = 1; i <= N; i++)
    {
        g += findG(i);
    }

    d = findD();

    if (d > 3 * g)
        cout << "D";
    else if (d < 3 * g)
        cout << "G";
    else if (d == 3 * g)
        cout << "DUDUDUNGA";
}