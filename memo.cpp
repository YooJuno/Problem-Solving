#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int P;
vector<pair<int, int>> graph[1001];

void Dijkstra()
{



}


int main()
{
    cin >> N >> M >> P;
    for(int i = 0; i < M; i++)
    {
        int src, dst;
        cin >> src >> dst >> time;

        graph[src].push_back({time, dst});
    }

    
    return 0;
}