#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 무한대를 나타내는 값
const int INF = 21e8;

// 다익스트라 알고리즘 구현
void dijkstra(int start, vector<vector<pair<int, int>>> &graph, vector<int> &dist)
{
    // 우선순위 큐 (최소 힙) 사용
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // 시작 노드의 최단 거리를 0으로 설정하고 큐에 삽입
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        // 현재 노드 정보 가져오기
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        // 기존 거리보다 크면 무시
        if (cost > dist[u])
        {
            continue;
        }
        
        // 인접 노드 확인
        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // 더 짧은 경로 발견 시 업데이트
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int V, E, start;
    cin >> V >> E >> start;
    
    vector<vector<pair<int, int>>> graph(V);
    vector<int> dist(V, INF);
    
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    dijkstra(start, graph, dist);
    
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }
    
    return 0;
}
