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

// Recursive O
void DFS(int cur)
{
    isVisited[cur] = true;
    cout << cur << ' ';

    for(auto i = 0; i < v[cur].size(); i++)
    {
        if(isVisited[v[cur][i]] == true) continue;        
        DFS(v[cur][i]);
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
    cout << "DFS : ";
    DFS(0);

    return 0;
}