#include <iostream>
#include <unordered_map>

using namespace std;

auto main() -> int
{
    unordered_map<int, int> um;
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        um[num]++;

    }
    
    for (int i = 0; i < M; i++)
    {
        int num; cin >> num;
        cout << um[num] << ' ';
    }
    cout << endl;
    
    return 0;
}