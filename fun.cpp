//
// Created by Lee ChanYoung on 2021/04/21.
//

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    gcd(b, a % b);
}

vector<string> split(string s, string separator) {
    vector<string> v;

    char *c = strtok((char *) s.c_str(), separator.c_str());

    while (c) {
        string token = c;

        if (!token.empty())
            v.push_back(token);

        c = strtok(NULL, separator.c_str());
    }
    return v;
}

vector<string> split2(string s, string separator) {
    vector<string> v;

    int preIndex = 0;
    int curIndex = s.find(separator, preIndex);
    while(curIndex != string::npos) {
        string token = s.substr(preIndex, curIndex - preIndex);

        if (!token.empty())
            v.push_back(token);

        preIndex = curIndex + separator.size();
        curIndex = s.find(separator, preIndex);
    }

    string token = s.substr(preIndex);

    if (!token.empty())
        v.push_back(token);

    return v;
}

vector <vector<int>> rotate(vector <vector<int>> &arr) {
    int r = arr.size();
    int c = arr[0].size();

    vector <vector<int>> newArr(c, vector<int>(r));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            newArr[i][j] = arr[r - j - 1][i];
        }
    }
    return newArr;
}

vector <vector<int>> reverse(vector <vector<int>> &arr) {
    vector <vector<int>> newArr(arr);

    for (auto &i : newArr) {
        reverse(i.begin(), i.end());
    }

    return newArr;
}