#include <iostream>
#include <cstring>

using namespace std;

struct Pos
{
    int y;
    int x;
};

int N;
int map[51][51];
bool isCaught[51][51];
bool isVisited[51][51];
Pos initPosition;
int result;

void Init()
{
    N = 0;
    result = 0;
    memset(map, 0, sizeof(map));
    memset(isCaught, false, sizeof(isCaught));
    memset(isVisited, false, sizeof(isVisited));
}

void Input()
{
    cin >> N;

    for(auto i = 0; i < N; i++)
    {
        for(auto j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2) 
            {
                initPosition = {i, j};
            }
        }
    }
}

void DFS(int depth, Pos pos)
{
    if(map[pos.y][pos.x] == 1 && isCaught[pos.y][pos.x] == false)
    {
        isCaught[pos.y][pos.x] = true;
        result++;
    }

    if(depth == 3)
    {
        return;
    }

    isVisited[pos.y][pos.x] = true;

    // y++
    bool didJump = false;
    for (int  i = pos.y + 1; i < N; i++)
    {   
        // 점프 전
        if(didJump == false)
        {
            // 점프
            if(map[i][pos.x] == 1)
            {
                didJump = true;
            }
        }
        // 점프 후
        else if(isVisited[i][pos.x] == false)
        {
            DFS(depth + 1, {i, pos.x});
            // 졸이 있으면
            if(map[i][pos.x] == 1)
            {
                break;
            }
            
        }
    }

    // y--
    didJump = false;
    for (int  i = pos.y - 1; i >= 0; i--)
    {
        // 점프 전
        if(didJump == false)
        {
            // 점프
            if(map[i][pos.x] == 1)
            {
                didJump = true;
            }
        }
        // 점프 후
        else if(isVisited[i][pos.x] == false)
        {
            DFS(depth + 1, {i, pos.x});
            // 졸이 있으면
            if(map[i][pos.x] == 1)
            {
                break;
            }
        }
    }

    // x++
    didJump = false;
    for (int  i = pos.x + 1; i < N; i++)
    {
        // 점프 전
        if(didJump == false)
        {
            // 점프
            if(map[pos.y][i] == 1)
            {
                didJump = true;
            }
        }
        // 점프 후
        else if(isVisited[pos.y][i] == false)
        {
            DFS(depth + 1, {pos.y, i});
            // 졸이 있으면
            if(map[pos.y][i] == 1)
            {
                break;
            }
        }
    }

    // x--
    didJump = false;
    for (int  i = pos.x - 1; i >= 0; i--)
    {
        // 점프 전
        if(didJump == false)
        {
            // 점프
            if(map[pos.y][i] == 1)
            {
                didJump = true;
            }
        }
        // 점프 후
        else if(isVisited[pos.y][i] == false)
        {
            DFS(depth + 1, {pos.y, i});
            // 졸이 있으면
            if(map[pos.y][i] == 1)
            {
                break;
            }
        }
    }

    isVisited[pos.y][pos.x] = false;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        Init();
        Input();
        DFS(0, initPosition);
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}