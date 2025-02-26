#include <iostream>
#include <vector>

/*

[ MST ] 최소 신장 트리
- Edge들을 오름차순으로 정렬해서 작은 Edge를 추가해가며 그래프를 구성
- 만약 중간에 Cycle이 생기면 탈락

Kruskal : Edge가 많으면 사용 (Union Find 사용)

[ 내 궁금증 ]
- 루트와 부모가 같은지? 그게 너무 헷갈림
- 결국엔 루트를 기준으로 비교를 해야될거 같음.

*/

struct Edge
{
	int a;
	int b;
	int cost;
}

int parent[9];

struct Edge edge[9] = {
	{1, 2, 1},
	{1, 3, 6},
	{1, 4, 2},
	{2, 3, 8},
	{2, 5, 9},
	{2, 6, 3},
	{3, 4, 3},
	{4, 5, 7},
	{5, 6, 2}
};

int find(int target)
{
	if(target == parent[target]) 
        return target;

	int ret = find(parent[target]);
	return ret;
}

void setUnion()
{
	
}

bool isCycle(int src, int dst)
{

}

void MST()
{
	
}

auto main() -> int
{
    for(auto i = 1; i <= 9; i++)
    {
        parent[i] = i;
    }
	MST();

	return 0;
}