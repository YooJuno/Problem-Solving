#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 역의 수
int K; // 하나의 하이퍼 튜브가 연결하는 역의 수
int M; // 하이퍼 튜브의 수

vector<int> v[100001 + 1000];
bool isVisited[100001 + 1000];

int BFS(int src)
{
    int result = -1;
    queue<int> q;
    q.push(src);

    isVisited[src];

    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        for(auto next : v[now])
        {
            if(isVisited[next] == true) 
            {
                continue;
            }
            if(next == N)
            {
                return result + 1;
            }

            isVisited[next] = true;
            result++;
            
            q.push(next);
        }
    }

    return -1;
}

auto main() -> int
{
    cin >> N >> K >> M;

    for(auto i = 0; i < M; i++)
    {
        for(auto j = 0; j < K; j++)
        {
            int station; cin >> station;
            v[i+100000].push_back(station);
            v[station].push_back(i+100000);
        }
    }

    cout << BFS(1);
    
    return 0;
}