#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

/*
[Graph]
0 1 1 0 0 0 0
1 0 0 1 1 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0

[탐색 순서]
DFS : 0 - 1 - 3 - 4 - 2 - 5 - 6
BFS : 0 - 1 - 2 - 3 - 4 - 5 - 6
*/

int N = 7;
int edge = 6;
int input[6][2] = {
    {0, 1},
    {0, 2},
    {1, 3},
    {1, 4},
    {2, 5},
    {2, 6}
};

vector<int> v[7];
bool isVisited[7];

// Recursive X
// BFS는 edge별 cost가 동일할때 좋음
// 근데 edge별 cost가 다르면... dijkstra 사용
void BFS(int cur)
{
    isVisited[cur] = true;
    deque<int> dq;
    dq.push_back(cur);

    while(!dq.empty()/*모든 노드를 순회하기 전까지 순회*/)
    {
        // 현재 노드는 큐에서 없애야현재 노드를 BFS로 순회할 수 있음.
        // 즉 now에 들어온다는 것은, now에 직접 연결되어있는 하위노드들을 순회
        int now = dq.front();
        cout << now << ' ';
        dq.pop_front();

        // now에 연결되어있는 모든 노드를 visit
        for(auto i = 0; i < v[now].size(); i++)
        {
            if(isVisited[v[now][i]] == true)
                continue;

            isVisited[v[now][i]] = true;
            dq.push_back(v[now][i]);
        }
    }
}

auto main() -> int
{
    for(auto i = 0; i < edge; i++)
    {
        // 양뱡향 그래프
        v[input[i][0]].push_back(input[i][1]);
        v[input[i][1]].push_back(input[i][0]);
    }

    memset(isVisited, 0, sizeof(isVisited));
    cout << "\nBFS : ";
    BFS(0);

    return 0;
}