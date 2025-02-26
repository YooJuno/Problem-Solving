#include <iostream>

using namespace std;

/*
[최단거리 알고리즘]
- 코스트가 다를 때 (BFS는 코스트가 같음)
- 모든 시작점에서, 모든 정점으로 가는 최소
*/

/*
- PQ 하나를 사용해야함.
- 현재 노드에 연결되어 있는 인접 노드를 PQ에 넣음
- 현재 가중치 + cost가  목적 노드의 가중치보다 낮으면(초기 값은 21e8) 가중치 갱신
- isVisited 필요 없음. 어차피 가중치로 비교할거라서.
- min() 사용해야됨.
- cmp 함수 필요
    - 정수 내림차순 할거면 greater<int> 쓰면 되는데, 위치와 cost도 고려해야함
    - 즉, 비교함수를 직접 만들어줘야함.
*/


struct Edge
{
    int target; // 직접 연결된 노드
    int costToTarget; // target까지의 비용
};

struct CMP
{
    bool operator()(Egde a, Edge b)
    {
        // 오름차순
        return a.costToTarget > b.costToTarget;
    }
};

int N;
int M;
int dist[100001];

void dijkstra(int src)
{
    // prioruty_queue<자료형, Container, 비교함수> pq : 비교함수에 따라 정렬
    prioruty_queue<Edge, vector<Edge>, CMP> pq;
    
    // 자기 자신 cost는 0
    pq.push({src, 0});

    // dist는 모두 INF로 초기화 상태

    while(!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        // 현재
        if(dist[now.target] < now.costToTarget)
        {
            continue;
        }

        for(auto i = 0; i < v[now.target].size(); i++)
        {
            
            int target = v[now.target][i].target;
            int costToTarget = now.costToTarget + v[now.target][i].costToTarget;

            if(costToTarget < dist[target])
            {
                dist[target] = costToTarget;
                pq.push({tar, costToTarget});
            }
        }
    }

    // prioruty_queue<자료형> pq : 선언한 자료형 변수들을 내림차순으로 정렬
}

int main()
{
    cin >> N >> M;
    
    for(auto i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }

    for(auto i = 1; i <= M; i++)
    {
        dist[i] = 21e8;
    }
    
    // 시작 노드
    dijkstra(1);
    return 0;
}