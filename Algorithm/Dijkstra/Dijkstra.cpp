#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int A, B;
vector<pair<int, int>> graph[1001];
int parent[1001];
int dist[1001];
void Dijkstra(int src, int dst)
{
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 21e8;
    }
    memset(parent, -1, sizeof(parent));
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    parent[src] = -1;
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

        for(auto neighbor : graph[u])
        {
            int weight = neighbor.first;
            int v = neighbor.second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int f, t, c;
        cin >> f >> t >> c;
        graph[f].push_back({c, t});
        graph[t].push_back({c, f});
    }
    
    
    Dijkstra(1, N);
    cout << endl;
    int cur = N;
    while(parent[cur] != -1)
    {
        cout << cur << ' ';
        cur = parent[cur];
    }
    cout << endl;
    
    return 0;
}

/*
6 9
1 2 1
1 4 7
1 5 3
2 3 2
3 5 4
3 6 5
4 5 8
4 6 9
5 6 6

*/