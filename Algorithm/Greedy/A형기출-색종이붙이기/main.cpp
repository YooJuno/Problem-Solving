#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool map[10][10];
int cnt[6];
int boxSize[10][10];

struct Pos
{
    int y;
    int x;
};


void Init()
{
    for (int i = 0; i <= 5; i++)
    {
        cnt[i] = 5;
    }

    memset(map, false, sizeof(map));
    memset(boxSize, 0, sizeof(boxSize));
}

void Input()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
        }
    }
}

int calcBoxSize(Pos pos)
{
    int maxSize;
    for (maxSize = 1; maxSize <= 5; maxSize++)
    {
        bool isRect = true;
        for (int i = pos.y; i < pos.y + maxSize; i++)
        {
            for (int j = pos.x; j < pos.x + maxSize; j++)
            {
                if(map[i][j] == false)
                {
                    return maxSize - 1;
                }
            }
        }
    }
    
    return maxSize;
}

bool isFinished()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(map[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

struct cmp
{
    bool operand(pair<int, Pos> a, pair<int, Pos> b)
    {
        return a.first > b.first;
    }
};

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        
        Init();
        Input();

        priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, cmp> pq;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(map[i][j] == 1)
                {
                    pq.push({calcBoxSize({i,j}), {i, j}});
                }
            }
        }

        while(isFinished() == false)
        {
            int size = pq.top().first;
            Pos pos = pq.top().second;
            pq.pop();

            if(cnt[size] == 0) continue;

            cnt[size]--;

            for (int i = pos.y; i < pos.y + size ; i++)
            {
                for (int j = pos.x; j < pos.x + size; j++)
                {
                    map[i][j] = false;
                }
            }         
            
            result++;
        }
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}