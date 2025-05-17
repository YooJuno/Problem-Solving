#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int T;
vector<int> graph[101];
bool isVisited[101][101];
queue<int> q;

bool bfs(int src, int dst)
{
    memset(isVisited, false, sizeof(isVisited));
    q.push(src);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        if(u == dst) 
        {
            return true;
        }

        for(const auto &v : graph[u])
        {
            if(isVisited[u][v] == true) continue;

            isVisited[u][v] = true;
            q.push(v);
        }
    }

    return false;
}

int main()
{
    cin >> N;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    
    int coco, marry;
    cin >> coco >> marry;

    bfs(coco, marry) ? cout << "YES\n" : cout << "NO\n";
    
    return 0;
}

/*
6
4
1 2
3 1
3 4
5 6
1
5
*/