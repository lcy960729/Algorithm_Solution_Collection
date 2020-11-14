//
// Created by CY on 2020-09-08.
//
//
// Created by lcy96 on 2020-09-04.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

ll N, B;

vector<vector<int>> multi(vector<vector<int>> matrixA, vector<vector<int>> matrixB) {
    vector<vector<int>> result(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                sum += (matrixA[i][k] * matrixB[k][j]) % 1000;
            }
            result[i][j] = sum % 1000;
        }
    }
    return result;
}

vector<vector<int>> dc(vector<vector<int>>& matrix, ll b) {
    if (b == 1){
        vector<vector<int>> result(N, vector<int>(N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i == j)
                    result[i][j] = 1;
                else
                    result[i][j] = 0;
            }
        }
        return result;
    }

    if (b == 2) {
        return multi(matrix, matrix);
    }

    vector<vector<int>> result;
    if (b % 2 == 0) {
        result = dc(matrix, b / 2);
        result = multi(result, result);
    }else{
        result = dc(matrix, b - 1);
        result = multi(result, matrix);
    }

    return result;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> B;

    vector<vector<int>> matrix(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    if (B != 1)
        matrix = dc(matrix, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}
