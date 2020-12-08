////
//// Created by LeeChanYoung on 2020/11/22.
////
//
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//
//#define pii pair<int, int>
//#define ll long long
//#define Int_MAX 1e9
//#define LL_MAX 3e18
//
//using namespace std;
//
//int N, M;
//
//int store[1001];
//
//int main(){
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//#endif
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    cin >> N >> M;
//
//    int ans = 0;
//    for (int i = 0; i < N; i++){
//        int brand;
//        cin >> brand;
//
//        ans = max(ans, ++store[brand]);
//    }
//}

#include <stdio.h>
#include<string.h>

void set_proverb(const char** q, int n);

int main() {
    const char* i;
    int n;
    printf("몇 번째 속담을 선택하시겠습니까?");
    scanf("%d", &n);

    set_proverb(&i, n);
    printf("selected proverb = %s \n", i);

    return 0;
}

void set_proverb(const char** q, int n) {
    static const char* array[10] = { "A bad shearer never had a good sickle.",
            "A bad workman (always) blames his tools",
            "Scratch my back and I will scratch yours.",
            "Perfect understanding will sometimes almost extinguish pleasure.",
            "Success is a ladder that cannot be climbed with your hands in your pockets.",
            "Fire is put out by fire.",
            "He who can lick can bite.",
            "Knowledge finds its price.",
            "All the passions are sisters.",
            "Patience is the art of hoping."
    };
    *q = array[n - 1];
}