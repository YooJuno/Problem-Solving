#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
vector<pair<int, int>> graph[1001];
int A, B;
int p[1001];

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {   
        return a.first > b.second;
    }
};


void djikstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push()

}

int main()
{
    cin >> N >> M >> K;
    cin >> A >> B;

    for (int i = 0; i < M; i++)
    {
        int f, t, c;
        cin >> f >> t >> c;
        graph[f].push_back({t, c});
        graph[t].push_back({f, c});
    }

    for (int i = 0; i < K; i++)
    {
        cin >> p[i];
    }
    
    return 0;
}