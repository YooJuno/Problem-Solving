#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

auto main() -> int
{
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
    
    return 0;
}