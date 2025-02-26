#include <iostream>
#include <cstring>

using namespace std;

int minV;   
int map[16][16];
int N;
int visited[16];

void recursive(int depth, int idx)
{
    if(depth == N/2)
    {
        int sumLeft = 0;
        int sumRight = 0;
        int cntLeft = 0;
        int cntRight = 0;
        int arrLeft[8] = {0,};
        int arrRight[8] = {0,};
        for(int i=0; i<N; i++)
        {
            if(visited[i]) 
                arrLeft[cntLeft++] = i;
            else  
                arrRight[cntRight++] = i;
        }
        for(int i=0; i<N/2-1; i++)
        {
            for(auto j = i+1; j < N/2; j++)
            {
                sumLeft += map[arrLeft[i]][arrLeft[j]];
                sumRight += map[arrRight[i]][arrRight[j]];
            }
        }
        if(minV > abs(sumLeft - sumRight))
            minV = abs(sumLeft - sumRight);
    
        return;
    }

    for(auto i = idx; i < N; i++)
    {
        visited[i] = true;
        recursive(depth+1, i+1);
        visited[i] = false;
    }
}

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    // for(auto test_case=1; test_case<=1; test_case++)
    {
        int result = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cin >> N;
        minV = 20000*16*16;

        for(auto i = 0; i < N; i++)
            for(auto j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if(i > j) map[j][i] += map[i][j];
            }
        
        recursive(0, 0);
        
        cout << '#' << test_case << ' ' << minV << endl;
    }
    return 0;
}