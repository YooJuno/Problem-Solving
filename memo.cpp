#include <iostream>
<<<<<<< HEAD
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
=======
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
>>>>>>> ac595b56b654fe9984fac7db7833291af9eecb47

auto main() -> int
{
<<<<<<< HEAD
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);


    int src = 0, dst = 0;
    int cnt = 0;
    for(auto e : v)
    {
        src = e.first;

        if(src >= dst)
        {
            cnt++;
            dst = e.second;
        }

    }
    cout << cnt << endl;
    
=======
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

        

>>>>>>> ac595b56b654fe9984fac7db7833291af9eecb47
    return 0;
}