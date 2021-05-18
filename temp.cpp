//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <cmath>
//#include <map>
//#include <list>
//
//#define pii pair<int, int>
//#define ll long long
//#define Int_MAX 1e9
//#define LL_MAX 3e18
//
//using namespace std;
//
//int main() {
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int N, K;
//    cin >> N >> K;
//
//    string s;
//    cin >> s;
//
//    pii cur;
//
//    map<int, list<pii>> plus, minus;
//
//    vector<pii > flowers(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> flowers[i].second >> flowers[i].first;
//
//        if (i == 0) {
//            cur = flowers[i];
//        }
//    }
//
//    for (int i = 0; i < N; ++i) {
//        int sum = flowers[i].first + flowers[i].second;
//        int diff = flowers[i].first - flowers[i].second;
//
//        if (plus.find(sum) == plus.end())
//            plus.insert({sum, list<pii >()});
//
//        if (minus.find(diff) == minus.end())
//            minus.insert({diff, list<pii >()});
//
//        for (int j = 0; j < N; ++j) {
//            if (sum == flowers[j].first + flowers[j].second) {
//                plus[sum].push_back(flowers[j]);
//            } else if (diff == flowers[j].first + flowers[j].second) {
//                minus[diff].push_back(flowers[j]);
//            }
//        }
//    }
//
//    for (auto &list : plus) {
//        list.second.push_back(make_pair(1,1));
//        list.second.sort();
//    }
//
//    for (auto &list : minus) {
//        list.second.sort();
//    }
//
//    for (char c : s) {
//        //A, D => D에서 A로 올라감 \
//        //B, C => C에서 B로 올라감 /
//
//        int sum = cur.first + cur.second;
//        int diff = cur.first - cur.second;
//
//        list < pii > *plist;
//        if (c == 'A' || c == 'D') {
//            plist = &plus[sum];
//        } else {
//            plist = &minus[diff];
//        }
//
//        list<pii >::iterator now = find(plist->begin(), plist->end(), cur);
//        if (now == plist->end()) continue;
//
//        list<pii >::iterator next = now;
//        if (c == 'A' || c == 'B') {
//            next++;
//        } else {
//            next--;
//        }
//
//        if (next != plist->end() && next != --plist->begin()) {
//            plist->erase(now);
//        }
//    }
//
//    cout << cur.second << ' ' << cur.first << '\n';
//}
