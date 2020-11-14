#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int t;
    int a;
    int h;
} RoomInfo;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int h_ATK;
    cin >> h_ATK;

    RoomInfo roomInfo[123457];
    for (int i = 0; i < n; i++){
        RoomInfo &room =  roomInfo[i];

        cin >> room.t;
        cin >> room.a;
        cin >> room.h;
    }

    long long left = 0, mid = 0, right = 9223372036854775806;

    while (left + 1 < right)
    {
        mid = (left + right) / 2 ;

        long long hero_hp = mid;
        long long hero_atk = h_ATK;

        for (int i = 0; i < n; i++){
            RoomInfo &currentRoom =  roomInfo[i];

            if (currentRoom.t == 1){
                long long monster_hp = currentRoom.h;
                long long monster_atk = currentRoom.a;

                int atk_count = monster_hp / hero_atk;

                if (monster_hp % hero_atk == 0)
                    atk_count--;

                hero_hp -= monster_atk * atk_count;

                if (hero_hp <= 0)
                    break;

            }else if (currentRoom.t == 2){
                hero_atk += currentRoom.a;
                hero_hp = (hero_hp + currentRoom.h >= mid) ? mid : hero_hp + currentRoom.h;
            }
        }

        if (hero_hp <= 0)
            left = mid;
        else
            right = mid;
    }
    
    cout << right << "\n";
}