#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 저장하는 구조체
struct Edge 
{
    int u, v, weight;
    
    // 간선을 가중치 기준으로 정렬하기 위한 연산자 오버로딩
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

// 유니온-파인드 자료구조를 위한 부모 배열
vector<int> parent;

// 특정 원소의 대표(루트) 노드를 찾는 함수 (경로 압축 적용)
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]); // 경로 압축 기법 적용
}

// 두 집합을 합치는 함수 (항상 더 작은 값이 부모가 되도록 설정)
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if (a != b) // 사이클을 방지하기 위해 루트가 다를 때만 합침
    {
		// 더 작은 값이 부모가 되도록 설정
		parent[max(a, b)] = min(a, b);
    }
}

// 크루스칼 알고리즘 구현
int kruskal(int V, vector<Edge> &edges)
{
    // 간선을 가중치 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end());
    
    // 부모 배열 초기화 (각 정점이 자기 자신을 가리키도록 설정)
    parent.resize(V);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    
    int mst_weight = 0; // 최소 신장 트리의 가중치 합
    int edges_used = 0; // 선택된 간선 개수
    
    // 간선들을 순회하며 최소 신장 트리를 구성
    for (const auto &edge : edges)
    {
        if (find(edge.u) != find(edge.v)) // 같은 집합이 아니라면 선택
        {
            unite(edge.u, edge.v); // 두 정점을 하나의 집합으로 합침
            mst_weight += edge.weight; // MST 가중치 합 갱신
            edges_used++;
            
            if (edges_used == V - 1) // MST는 V-1개의 간선으로 완성됨
            {
                break;
            }
        }
    }
    
    return mst_weight;
}

int main()
{
    int V, E; // 정점(V)과 간선(E)의 개수 입력
    cin >> V >> E;
    
    vector<Edge> edges(E); // 간선 정보를 저장할 벡터
    
    // 간선 정보 입력 (u, v, weight)
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    // 크루스칼 알고리즘 실행 후 최소 신장 트리의 가중치 출력
    cout << kruskal(V, edges) << endl;
    
    return 0;
}
