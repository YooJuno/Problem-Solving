#include <iostream>

using namespace std;

int N;
int parent[1000];
bool graph[1000][1000];

int find(int x)
{
    if(parent[x] == x)
    {
        return x;
    }

    return parent[x] = find(parent[x]);
}

int unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    printf("%d %d\n", rootA, rootB);
    if(rootA == rootB)
    {
        return true;
    }

    parent[rootB] = rootA;
    return false;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "parent : ";
    for (int i = 0; i < N; i++)
    {
        cout << parent[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if(graph[i][j] == true)
            {
                printf("i:%d j:%d => ", i, j);
                unite(i, j);
                cout << "parent : ";
                for (int k = 0; k < N; k++)
                {
                    cout << parent[k] << ' ';
                }
                cout << endl;
                // if(unite(i, j))
                // {
                //     cout << "WARNING\n";
                //     return 0;
                // }
            }
        }   
    }
        
    // cout << "STABLE\n";
    return 0;
}
