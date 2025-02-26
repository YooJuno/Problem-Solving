#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int y;
    int x;
};

int N;
int M;

bool map[101][101];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

void BFS(Pos src)
{
    queue<Pos> q;
    q.push(src);
    map[src.y][src.x] = false;

    while(!q.empty())
    {
        Pos now = q.front();
        q.pop();

        for(auto i = 0; i <4 ; i++)
        {
            Pos next = {now.y + dy[i], now.x + dx[i]};
            if(next.y < 0 || next.y > N-1 || next.x < 0 || next.x > M-1)
            {
                continue;
            }
            if(map[next.y][next.x] == false) 
            {
                continue;
            }    
            
            map[next.y][next.x] = false;
            q.push(next);
        }
    }

}

auto main() -> int
{
    cin >> N >> M;

    for(auto i = 0; i < N; i++)
    {
        for(auto j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }   
    
    int cnt = 0;
    for(auto i = 0; i < N; i++)
    {
        for(auto j = 0; j < M; j++)
        {
            if(map[i][j])
            {
                BFS({i, j});
                cnt++;
            }
        }
    }

    cout << cnt;
    
    return 0;
}