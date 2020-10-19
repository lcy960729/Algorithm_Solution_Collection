#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Student
{
    string name;
    int kor;
    int eng;
    int math;
} student;

student s[100000];

bool cmp(student s1, student s2)
{
    if (s1.kor == s2.kor){
        if (s1.eng == s2.eng){
            if (s1.math == s2.math){
                return s1.name < s2.name;
            }
            else{
                return s1.math > s2.math;
            }
        }else{
            return s1.eng < s2.eng;
        }
    }else{
        return s1.kor > s2.kor;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].name;
        cin >> s[i].kor;
        cin >> s[i].eng;
        cin >> s[i].math;
    }

    sort(s, s + n, cmp);

    for (int i = 0; i < n; i++)
    {
        cout << s[i].name << "\n";
    }
}