/*

[Flood Fill]
- DFS 혹은 BFS를 사용하여 2차원 맵에서의 문제를 푸는 것
- 주변 방향으로 "퍼져나가는 방향" 이라면 BFS가 더 좋긴함.
- 기존엔 
    bool visited[] 였다면...
            |
            v
    bool isVisited[][]; // 2차원 배열형식이 필요함
*/
#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int y;
    int x;
};

int H, W;
int redY, redX;
int blueY, blueX;
int N;

int map[101][101];
bool isVisited[101][101];
int timer[101][101];

int dx[8] = {2, 3, 3, 2, -2, -3, -3, -2};
int dy[8] = {-3, -2, 2, 3, 3, 2, -2, -3};


int BFS(Pos src)
{
    queue<Pos> q;
    q.push(src);
    isVisited[src.y][src.x] = true;

    while(!q.empty())
    {
        Pos now = q.front();
        q.pop();

        for(auto i = 0; i < 8; i++)
        {
            Pos next = {now.y + dy[i], now.x + dx[i]};

            // Map 범위 설정 필요함
            if(next.y < 0 || next.x < 0 || next.y > H-1 || next.x > W-1)
            {
                continue;
            }
            // 방문 표시
            if(isVisited[next.y][next.x] == true)
            {
                continue;
            }
            // 가지치기
            if(map[next.y][next.x] == 1)
            {
                continue;
            }
            else if(map[next.y][next.x] == 2)
            {
                return timer[now.y][now.x] + 1;
            }
            else
            {
                isVisited[next.y][next.x] = true;
                timer[next.y][next.x] = timer[now.y][now.x] + 1;
                q.push(next);
            }
        }
    }

    return -1;
}

auto main() -> int
{
    cin >> H >> W;
    cin >> redY >> redX;
    cin >> blueY >> blueX;
    cin >> N;

    map[blueY][blueX] = 2;

    for(auto i = 0; i < N; i++)
    {
        int soldierY, soldierX;
        cin >> soldierY >> soldierX;
        map[soldierY][soldierX] = 1;

    }
    
    cout << BFS({redY, redX});
    
    return 0;
}