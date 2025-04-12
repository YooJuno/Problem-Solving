#include <iostream>
<<<<<<< HEAD

int main()
{
    std::cout << "Hello SSAFY!";
=======
<<<<<<< HEAD
=======
#include <vector>
>>>>>>> 2c6ecdc9f401e23fea6287fa834138513d44297a
#include <algorithm>

using namespace std;

<<<<<<< HEAD


=======
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
>>>>>>> 2c6ecdc9f401e23fea6287fa834138513d44297a

int find(int x)
{
<<<<<<< HEAD
    
=======
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
>>>>>>> 2c6ecdc9f401e23fea6287fa834138513d44297a

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
    
>>>>>>> 696f0879f9ad182108ee2cf483c2709b16c1d551
    
    return 0;
}




