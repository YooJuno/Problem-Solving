#include <iostream>

using namespace std;

int dp[100001];

/*
[점화식]
1. dp[0] = 0
2. dp[1] = 1
3. dp[i] = dp[i-1] + dp[i-2] (i > 1)
*/

int Fib(int x)
{
    if(x <= 1) 
    {
        return 1;
    }

    for(int i = 0; i <= x; i++)
    {
        if(dp[i] == 0)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
    }

    return dp[x];
}

int main()
{
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;

    cout << Fib(N) << endl;
    
    return 0;
}