#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    char word[1000000];

    cin.getline(word, sizeof(word));

    int count = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (count == 0)
        {
            if (word[i] != ' ' && word[i] != '\0'){
                count++;
            }
        }
        else
        {
            if (word[i] == ' ' && (word[i+1] != ' ' && word[i+1] != '\0'))
            {
                count++;
            }
        }
    }
    cout << count;
}