#include <iostream>

using namespace std;

auto recursive(int depth, int N) -> int
{
    if(depth == N) 
    {
        cout << depth << " = ";
        return depth;
    }

    cout << depth << " + ";
    return depth + recursive(depth + 1, N);
}

auto main() -> int
{
    int N = 10;
    cout << recursive(0, 10);
    
    return 0;
}