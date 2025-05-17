#include <iostream>
#include <vector>

using namespace std;

int N;
bool isVisited[1000];
int maxCost = 0;
int minCost = 21e8;
int graph[1000][1000];

void dfs(int cur, int dst, int cost)
{
    if(cur == dst)
    {
        if(cost < minCost)
        {
            minCost = cost;
        }
        if(cost > maxCost){
            maxCost = cost;
        }
    }   
    for (int i = 0; i < N; i++)
    {
        if(graph[cur][i] != 0 && isVisited[i] == false)
        {
            isVisited[i] = true;
            dfs(i, dst, cost + graph[cur][i]);
            isVisited[i] = false;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {   
        for (int j = 0; j < N; j++)
        {
            int cost;
            cin >> cost;
            graph[i][j] = cost;
        }
    }
    
    int src, dst;
    cin >> src >> dst;

    isVisited[src] = true;
    dfs(src, dst, 0);
    isVisited[src] = false;

    cout << minCost << endl << maxCost << endl;
    
    return 0;
}