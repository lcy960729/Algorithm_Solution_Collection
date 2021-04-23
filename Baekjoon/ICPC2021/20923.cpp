#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <deque>

#define pii pair<int, int>
#define ll long long
#define Int_MAX 1e9
#define LL_MAX 3e18

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n, m;
    cin >> n >> m;

    deque<int> do_deck, su_deck, do_ground, su_ground;

    for (int i = 0; i < n; ++i) {
        int c1, c2;
        cin >> c1 >> c2;

        do_deck.push_back(c1);
        su_deck.push_back(c2);
    }

    int turn = -1;
    while (m--) {
        if (++turn % 2 == 0){
            do_ground.push_back(do_deck.back());
            do_deck.pop_back();

            if (do_deck.empty()) {
                cout << "su\n";
                return 0;
            }
        }else{
            su_ground.push_back(su_deck.back());
            su_deck.pop_back();

            if (su_deck.empty()) {
                cout << "do\n";
                return 0;
            }
        }

        int do_top = do_ground.empty() ? 0 : do_ground.back();
        int su_top = su_ground.empty() ? 0 : su_ground.back();

        if (do_top == 5 || su_top == 5) {
            while (!su_ground.empty()) {
                do_deck.push_front(su_ground.front());
                su_ground.pop_front();
            }
            while (!do_ground.empty()) {
                do_deck.push_front(do_ground.front());
                do_ground.pop_front();
            }
        }
        else if (do_top + su_top == 5) {
            while (!do_ground.empty()) {
                su_deck.push_front(do_ground.front());
                do_ground.pop_front();
            }
            while (!su_ground.empty()) {
                su_deck.push_front(su_ground.front());
                su_ground.pop_front();
            }
        }
    }

    int ans = do_deck.size() - su_deck.size();

    if (ans > 0) {
        cout << "do\n";
    } else if (ans < 0) {
        cout << "su\n";
    } else {
        cout << "dosu\n";
    }
}