#include <iostream>

using namespace std;

void rotateMagnet(bool circle[8], int direction)
{
    // 시계방향
    if(direction == true)
    {
        bool temp = circle[7];
        for(auto i = 6; i >= 0; i--)
        {
            circle[i+1] = circle[i];
        }
        circle[0] = temp;
    }
    // 반시계방향
    else if(direction == false)
    {
        bool temp = circle[0];
        for(auto i = 0; i < 7; i++)
        {
            circle[i] = circle[i+1];
        }
        circle[7] = temp;
    }
}

void recursive(bool magnet[4][8], int index, bool rotateDirection, bool left, bool right, bool preMagnet)
{
    if(index == -1 || index == 4) return;

    bool mag2=magnet[index][2];
    bool mag6=magnet[index][6];

    if((left==true && preMagnet != magnet[index][2]) || (right==true && preMagnet != magnet[index][6]) || (left==true && right==true))   
        rotateMagnet(magnet[index], rotateDirection);
    else
        return;

    if(left == true) recursive(magnet, index-1, !rotateDirection, 1, 0, mag6);
    if(right == true) recursive(magnet, index+1, !rotateDirection, 0, 1, mag2);
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        int K; cin >> K;
        
        bool magnet[4][8];
        for(auto i = 0; i < 4; i++)
        {
            for(auto j = 0; j < 8; j++)
            {
                cin >> magnet[i][j]; // 0:N , 1:S
            }
        }

        for(auto i = 0; i < K; i++)
        {
            int index; cin >> index; // #1 ~ #4
            int rotateDirection; cin >> rotateDirection; // 1:시계방향 , -1:반시계방향

            recursive(magnet, index-1, rotateDirection+1, 1, 1, -1); // magnet, idx, direction, left, right
        }
        
        result += magnet[0][0];
        result += magnet[1][0] * 2;
        result += magnet[2][0] * 4;
        result += magnet[3][0] * 8;
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}