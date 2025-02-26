#include <iostream>

using namespace std;

/*
[최단거리 알고리즘]
- 코스트가 다를 때 (BFS는 코스트가 같음)
- 모든 시작점에서, 모든 정점으로 가는 최소
*/

/*
- PQ 하나를 사용해야함.
- 현재 노드에 연결되어 있는 인접 노드를 PQ에 넣음
- 
- 현재 가중치 + cost가  목적 노드의 가중치보다 낮으면(초기 값은 21e8) 가중치 갱신
- isVisited 필요 없음. 어차피 가중치로 비교할거라서.
- min() 사용해야됨.
*/

void dijkstra()
{
    // prioruty_queue<자료형, Container, 비교함수> pq : 비교함수에 따라 정렬
    prioruty_queue<Edge, vector<Edge>, compare> pq;

    // prioruty_queue<자료형> pq : 선언한 자료형 변수들을 내림차순으로 정렬
}

int main()
{
    
    
    
    
    return 0;
}