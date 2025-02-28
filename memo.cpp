#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
int N;
int M;
int dist[1001];
vector<int> route;

int Dijkstra(int src, int dst)
{
    for(int i = 1; i <= N; i++)
    {
        dist[i] = 1e9;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty())
    {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(cost > dist[u])
        {
            continue;
        }
        
        int minCost = 1e9;
        
        for(auto neighbor : graph[u])
        {
            int weight = neighbor.first;
            int v = neighbor.second;
            
            if(dist[v] > dist[u] + weight)
            {
                cout << u << ' ';
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    cout << endl;
    
    return dist[dst];
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({C, B});
        graph[B].push_back({C, A});
    }

    cout << Dijkstra(1, N) << endl;
    
    return 0;
}