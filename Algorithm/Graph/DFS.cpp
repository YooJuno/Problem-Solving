#include <iostream>

using namespace std;

/*

[Depth-First Search]

깊이 갈 수 있는데까지 간다.
1. 모든 경우를 다 둘러봐야할 때 사용함.

[필요 기술]
- Vector(혹은 인접그래프)
- Visited 배열
- Recursive()

*/

0 0 1 0 1
1 0 0 1 0
0 1 1 0 0
0 0 1 1 0

int nodeCnt;
int arr[1001][1001];
int st, en;
bool visited[1001];


int DFS(int now, int cnt)
{
    if(now == en)
    {
        return cnt;
    }
    int maxCnt = 0;
    for(auto i = 0; i < nodeCnt; i++)
    {
        if(visited[i] == true)
            continue;
        if(arr[now][i] == 0)
            continue;

        visited[i] = true;

        int result = DFS(i, cnt + 1);
        if(result > maxCnt)
        {
            maxCnt = result;
        }

        visited[i] = false;
    }

    return maxCnt;
}

auto main() -> int
{
    cin >> nodeCnt;

    for(auto i = 0; i < nodeCnt; i++)
    {
        for(auto j = 0; j < nodeCnt; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cin >> st >> en;
    visited[st] = true;
    cout << DFS(st, 1);
    return 0;
}