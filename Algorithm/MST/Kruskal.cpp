#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u;
    int v;
    int weight;

    bool operator<(const Edge &target) const
    {
        return weight < target.weight;
    }
};

int parent[10001];
vector<Edge> edges;
int V;
int E;

int find(int x)
{
    if(parent[x] == x)
    {
        return x;
    }

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);

    if(rootA != rootB)
    {
        parent[rootB] = rootA;
    }
}

int Kruskal()
{
    int sumWeight = 0;
    int cntEdges = 0;
    for (int i = 0; i <= V; i++)
    {
        parent[i] = i;
    }
    

    sort(edges.begin(), edges.end());

    for(const auto &e : edges)
    {
        if(find(e.u) != find(e.v))
        {
            unite(e.u, e.v);
            sumWeight += e.weight;
            cntEdges++;

            if(cntEdges == V-1)
            {
                break;
            }
        }
    }

    return sumWeight;
}

auto main() -> int
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }
    
    cout << Kruskal() << endl;
    
    
    return 0;
}