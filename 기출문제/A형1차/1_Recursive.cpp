#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*
N개의 화분이 있음
두 종류의 화분이 있음

한 개의 화분에는 한 종류의 비료만 넣을 수 있음
해당 식물 바로 오른쪽에 똑같은 비료를 주면 p만큼 덜 자람.(누적 안됨)

*/

int N;
int P;
int heightA[21];
int heightB[21];


int recursive(int depth, int p, int height, bool isAB)
{
	if (depth == N)
	{
		return height - p;
	}

	int pB = 0;
	int pA = 0;

	if (depth > 0)
	{
		// 이전 비료가 A일 때
		if (!isAB)
		{
			pA = P;
			pB = 0;
		}
		// 이전 비료가 B일 때
		else 
		{
			pA = 0;
			pB = P;
		}	
	}

	int sumHeight = height - p;
	
	return sumHeight + max(recursive(depth+1, pA, heightA[depth], 0),
		recursive(depth+1, pB, heightB[depth], 1));
}

int main()
{
	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(heightA, 0, sizeof(heightA));
		memset(heightB, 0, sizeof(heightB));
		cin >> N; // 4 <= N <= 20
		cin >> P; // 1 <= P <= 30

		for (int i = 0; i < N; i++)
			cin >> heightA[i];
		for (int i = 0; i < N; i++)
			cin >> heightB[i];

		cout << '#' << test_case << ' ' << recursive(0, 0, 0, 0) << endl;
	}

	return 0;
}
