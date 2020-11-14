#include<iostream>

using namespace std;

typedef struct {
    int weight, height;
    int rank;
} Person;

int main(){
    int n;
    cin >> n;

    Person p[50];

    for (int i = 0; i < n; i++){
        cin >> p[i].weight;
        cin >> p[i].height;
        p[i].rank = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                continue;
                
            if (p[i].weight > p[j].weight && p[i].height > p[j].height)
                p[j].rank++;
        }
    }

    for (int i = 0; i < n; i++){
        cout << p[i].rank << " ";
    }
}