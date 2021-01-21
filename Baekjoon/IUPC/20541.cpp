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

struct Album {
    string name;
    Album *parent;
    map<string, Album *> *albums;
    set<string> *pictures;

    Album(const string &name, Album *album) {
        this->name = name;
        this->parent = album;
        this->albums = new map<string, Album *>;
        this->pictures = new set<string>;
    }

    ~Album() {
        delete albums;
        delete pictures;
    }

    void mkalb(string &s) {
        if (albums->find(s) != albums->end()) {
            cout << "duplicated album name\n";
        } else {
            albums->insert({s, new Album(s, this)});
        }
    }

    pii rmalb(Album *album) {
        pii ret = {1, album->pictures->size()};

        for (auto i : *album->albums) {
            pii temp = rmalb(i.second);

            ret.first += temp.first;
            ret.second += temp.second;
        }

        delete album;

        return ret;
    }

    void rmalb(string &s) {
        if (albums->empty()) {
            cout << 0 << ' ' << 0 << '\n';
            return;
        }

        pii ret = {0, 0};
        if (s == "-1") {
            ret = rmalb(albums->begin()->second);
            albums->erase(albums->begin());
        } else if (s == "0") {
            for (auto i : *albums) {
                pii temp = rmalb(i.second);

                ret.first += temp.first;
                ret.second += temp.second;
            }
            albums->clear();
        } else if (s == "1") {
            ret = rmalb(albums->rbegin()->second);
            albums->erase(--albums->end());
        } else {
            auto i = albums->find(s);
            if (i != albums->end()) {
                ret = rmalb(i->second);
                albums->erase(i);
            }
        }

        cout << ret.first << ' ' << ret.second << '\n';
    }

    void insert(string &s) {
        if (pictures->find(s) != pictures->end()) {
            cout << "duplicated photo name\n";
        } else {
            pictures->insert(s);
        }
    }

    void del(string &s) {
        int ret = 0;

        if (pictures->empty()) {
            cout << ret << '\n';
            return;
        }

        if (s == "-1") {
            ret = 1;
            pictures->erase(pictures->begin());
        } else if (s == "0") {
            ret = pictures->size();
            pictures->clear();
        } else if (s == "1") {
            ret = 1;
            pictures->erase(--pictures->end());
        } else {
            auto i = pictures->find(s);

            if (i != pictures->end()) {
                ret = 1;
                pictures->erase(i);
            }
        }

        cout << ret << '\n';
    }

    Album *ca(Album *album) {
        if (album->parent == nullptr)
            return album;

        return ca(album->parent);
    }

    Album *ca(string &s) {
        Album *next = this;

        if (s == "..") {
            if (this->parent != nullptr)
                next = this->parent;
        } else if (s == "/") {
            next = ca(this);
        } else {
            auto i = albums->find(s);
            if (i != albums->end())
                next = i->second;
        }
        cout << next->name << '\n';
        return next;
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Album *album = new Album("album", nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string op, arg;
        cin >> op >> arg;

        if (op == "mkalb") {
            album->mkalb(arg);
        } else if (op == "rmalb") {
            album->rmalb(arg);
        } else if (op == "insert") {
            album->insert(arg);
        } else if (op == "delete") {
            album->del(arg);
        } else if (op == "ca") {
            album = album->ca(arg);
        }
    }

    delete album;
}