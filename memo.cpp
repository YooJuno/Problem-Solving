#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2e9

using namespace std;

int N, E, K;

vector<pair<int, int>> graph[20001]; // v, weight
int dist[20001];

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};


bool cmpVector(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void Dijkstra(int src)
{
    for (int i = 0; i <= N; i++) dist[i] = INF;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    dist[src] = 0;
    pq.push({src, 0});

    while (!pq.empty())
    {
        int u = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(cost > dist[u]) continue;

        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> E >> K;

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     sort(graph[i].begin(), graph[i].end(), cmpVector);
    // }
    
    Dijkstra(K);

    for (int i = 1; i <= N; i++)
    {
        dist[i] == INF ? printf("INF\n") : printf("%d\n", dist[i]);
    }
    
    return 0;
}

