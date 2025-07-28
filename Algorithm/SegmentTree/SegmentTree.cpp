
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[] = 
{0, 1000, 3000, 1000, 500, 1000, 2000, 800, 1000};
// 암기해주세요!!!!!! 4배로 만들면 안전하게 index 에러를 피할 수 있다.
int segTree[4 * (sizeof(arr) / sizeof(int))];
int mini = INT_MAX;

int makeSeg(int index, int s, int e) 
{
	if (s == e) 
	{
		segTree[index] = arr[s];
		return segTree[index];
	}

	int mid = (s + e) / 2;
	int left = makeSeg(index * 2, s, mid);
	int right = makeSeg(index * 2 + 1, mid + 1, e);
	// segTree[index] = min(left, right);
	segTree[index] = left + right;
	
	return segTree[index];
}


void querySeg(int index, int s, int e, int ts, int te) 
{
	// 1. 현재 바라보고 있는 범위가 완벽하게 target 의 범위에 포함된다면
	//    -> 해당 위치에 저장된 값을 그대로 return
	if (ts <= s && e <= te) 
	{
		mini = min(mini, segTree[index]);
		return;
	}

	// 2. 현재 바라보고 있는 범위가 완벽하게 target 범위 밖으로 나간다면
	//    -> 계산에 영향이 없는 값을 return
	if (s > te || e < ts) return;

	// 3. 일부만 포함된다면
	int mid = (s + e) / 2;
	querySeg(index * 2, s, mid, ts, te);			// 왼쪽
	querySeg(index * 2 + 1, mid + 1, e, ts, te);	// 오른쪽
}

int updateSeg(int index, int s, int e, int targetIndex, int targetValue) 
{
	// 리프 노드인지 비교할 때 s == e 조건문을 써도 된다.
	// 다만, 이 때 범위밖을 먼저 검사 한 후 써야한다.
	// 즉, 아래처럼 위로 오면 버그난다!!!
	// -> 범위 밖인 리프 노드 값이 return 되어 버린다.
	// if (s == e) {}

	// 1. targetIndex 가 현재 바라보고 있는 범위 밖이라면
	if (targetIndex < s || e < targetIndex) return segTree[index];

	// 2. 변경할 리프 노드를 찾았다면
	// if (s == e) {}
	if (s == targetIndex && e == targetIndex) 
	{
		arr[targetIndex] = targetValue;
		segTree[index] = targetValue;
		return segTree[index];
	}

	// 3. 포함하고 있는 범위라면 (내려가는 과정)
	int mid = (s + e) / 2;
	int left = updateSeg(index * 2, s, mid, targetIndex, targetValue);
	int right = updateSeg(index * 2 + 1, mid + 1, e, targetIndex, targetValue);
	// 데이터 변경이 끝남 -> 돌아오면서 갱신해야 한다!!
	segTree[index] = min(left, right);

	return segTree[index];
}

int main() 
{
	int n = sizeof(arr) / sizeof(int) - 1;
	makeSeg(1, 1, n);

	int targetStart = 2;
	int targetEnd = 7;

	// int result = querySeg(1, 1, n, targetStart, targetEnd);
	// cout << result << endl;

	mini = INT_MAX;
	querySeg(1, 1, n, targetStart, targetEnd);
	cout << mini << endl;

	int targetIndex = 7;
	int targetValue = 400;
	updateSeg(1, 1, n, targetIndex, targetValue);

	mini = INT_MAX;
	querySeg(1, 1, n, targetStart, targetEnd);
	cout << mini << endl;

	int del = 1;

	return 0;
}
