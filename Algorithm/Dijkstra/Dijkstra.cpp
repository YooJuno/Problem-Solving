#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[100001];
int dist[100001];
int N;
int M;

void Dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 같아도 안됨. u 이전까지의 cost가 0일 수도 있어서
        if(dist[u] < cost)
        {
            continue;
        }

        for(auto neighbor : graph[u])
        {
            int weight = neighbor.first;
            int v = neighbor.second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int src;
    cin >> N >> M >> src;

    for(int i = 0; i < M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({cost, v});
    }

    for(int i = 1; i <= N; i++)
    {
        dist[i] = 21e8;
    }

    Dijkstra(src);

    cout << "src : " << src << endl;
    for(int i = 1; i <= N; i++)
    {
        cout << "[" << src << " -> " << i << "] : " << dist[i] << endl;
    }
    cout << endl;   
    
    return 0;
}

/*
6 7 1
1 2 4
1 3 2
2 4 4
2 5 5
3 5 4
4 6 1
5 6 2

*/