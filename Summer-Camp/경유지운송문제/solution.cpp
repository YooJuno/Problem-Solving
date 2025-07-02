#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> graph[1000];

void init(int n, int k, int sCity[], int eCity[], int mLimit[]) 
{
    N = n;
    for (int i = 0; i < N; i++) graph[i].clear();
    for (int i = 0; i < k; i++) 
	{
		// 양방향
        graph[sCity[i]].emplace_back(eCity[i], mLimit[i]);
        graph[eCity[i]].emplace_back(sCity[i], mLimit[i]);
    }
}

void add(int sCity, int eCity, int mLimit) 
{
	// 양방향
    graph[sCity].emplace_back(eCity, mLimit);
    graph[eCity].emplace_back(sCity, mLimit);
}

bool BFS(int src, int dst, int minWeight) 
{
	bool isVisited[1000];
	memset(isVisited, false, N);
    queue<int> q;
	
    q.push(src);
    isVisited[src] = true;

    while (!q.empty()) 
	{
        int cur = q.front(); 
		q.pop();

        if (cur == dst) return true;

        for (const auto &[next, weight] : graph[cur]) 
		{
            if (isVisited[next] == false && weight >= minWeight) 
			{
                isVisited[next] = true;
                q.push(next);
            }
        }
    }

    return false;
}

int calculate(int sCity, int eCity, int M, int mStopover[]) 
{
    vector<int> perm(M);
    for (int i = 0; i < M; i++) perm[i] = i;

    int left = 1, right = 30000, answer = -1;

	// 이분 탐색
    while (left <= right) 
	{
        int mid = (left + right) / 2;
        bool possible = false;

        do
		{
            bool valid = true;
            int current = sCity;
            for (int i = 0; i < M + 1; i++) 
			{
                if (BFS(current, mStopover[perm[i]], mid) == false) 
				{
                    valid = false;
                    break;
                }
                current = mStopover[perm[i]];
            }
            if (valid && BFS(current, eCity, mid)) 
			{
                possible = true;
                break;
            }

        } while (next_permutation(perm.begin(), perm.end()));

        if (possible) 
		{
            answer = mid;
            left = mid + 1;
        } 
		else 
		{
            right = mid - 1;
        }
    }

    return answer;
}
