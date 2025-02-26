#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[10];
int cnt;

void scale(int left, int right, int depth, int N, int sum)
{
    if(left < right)
    {
        return;
    }

    if(depth == N-1)
    {
        (cnt)++;
        return;
    }

    if(left >= sum+right)
    {   
        int juno=1;
        int hi=0;
        for(int i=0; i<N; i++)
        {
            if(arr[i] != -1)
            {
                hi++;
                juno *= hi;
            }
        }
        (cnt) += pow(2, hi)*juno;
        return;
    }

    for(int i=0; i<N ; i++)
    {   
        if(arr[i]==-1) continue;
        int temp = arr[i];
        arr[i] = -1;
        scale(left + temp, right, depth + 1, N, sum-temp);
        scale(left, right + temp, depth + 1, N, sum-temp); 
        arr[i] = temp;
    }
}

int main()
{
	freopen("sample_input.txt", "r", stdin);
	
    int T; cin>>T;
	
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        int sum = 0;
        cnt = 0;

        int N; cin >> N;
        memset(arr, 0, sizeof(arr));

        for(int i=0; i<N; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        for(int i=0; i<N; i++)
        {
            int temp = arr[i];
            arr[i] = -1;
            scale(temp, 0, 0, N, sum-temp);
            arr[i] = temp;
        }

        cout << '#' << test_case << ' ' << cnt << endl;
	}

    return 0;
}