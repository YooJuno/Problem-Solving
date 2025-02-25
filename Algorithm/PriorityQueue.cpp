#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
[필요 개념]
- Heap
- Queue
*/

struct Member
{
    int id;
    string name;
};

auto main() -> int
{
    priority_queue<int> pq;

    // 들어갈 때 반정열 상태로 들어감
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    cout << "Priority-Queue Size : " << pq.size() << endl;

    while(!pq.empty())
    {
        int now = pq.top();
        pq.pop();
    }

    Member members[3] = {{3, "박진수"}, {1, "김세빈"}, {2, "유하명"}};

    // 1. 아이디 기준 오름차순
    // 1) PQ
    
    // 2) Quick()

    // 2. 이름 가나다순
    // 1) PQ
    
    // 2) Quick()
    
    return 0;
}