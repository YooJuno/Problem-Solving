#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int y;
    int x;
};

struct cmd
{
    bool operator()(pair<int, Pos> a, pair<int, Pos> b)
    {
        return a.first > b.first;
    }
};

int N;
int M;

int main()
{
    priority_queue<pair<int, Pos>, vector<pair<int, Pos>>, cmd> pq;
    cin >> N >> M;
    for (int i = 0; i < N + M; i++)
    {
        int B, Y, X;
        cin >> B;
        if(B == 0)
        {
            pq.top().second.y, pq.top().second.x;
            pq.pop();
        }
        else
        {
            cin >> Y >> X;
            pq.push({B, {Y, X}});
        }
    }

        

    return 0;
}