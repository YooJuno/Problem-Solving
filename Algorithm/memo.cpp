#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N; 
int M;
int R;
int K;
vector<int> v[50];
bool isVisited[50]; 
int dist[50];

int BFS(int src)
{
    int result = 0;
    deque<int> dq;
    isVisited[src] = true
    dq.push_back(src);

    while(!dq.empty())
    {
        int now = dq.front();
        dq.pop_front();
        result++;
        cout << "now : " << now;
        
        for(auto next : v[now])
        {
            cout << " -> " << next;
            if(isVisited[next] == true) continue;
            isVisited[next] = true;

            dist[next] = dist[now] + 1;
            if(dist[next] > K) continue;

            dq.push_back(next);
        }
        cout << endl;
    }

    return result;
}

int main()
{
    cin >> N;
    cin >> M;
    
    for(int i = 0; i < M; i++)
    {
        int a, b; 
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    cin >> R;
    cin >> K;

    cout << BFS(R);
    
    return 0;
}