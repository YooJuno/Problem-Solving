#include <cstring>
#include <deque>
#include <iostream>

using namespace std;

/*

[BFS]
- 넓이 우선 탐색
- 현재 노드에 연결되어있는 모든 노드들을 Search한다
    - visited == true?
    - graph[i][j] == fals?
    - 방문하지 않은 노드라면 큐에 추가한다.
- 현재 노드에 연결되어 있는 노드들을 모두 순회 완료.
- 현재 노드 변수를 큐 맨 앞의 노드로 대체한다.
- 모든 노드를 순회 완료하면 종료.

[Graph]
0 1 1 0 0 0 0
1 0 0 1 1 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0
0 0 1 0 0 0 0

[탐색 순서]
DFS : 0 - 1 - 3 - 4 - 2 - 5 - 6
BFS : 0 - 1 - 2 - 3 - 4 - 5 - 6
*/

bool arr[7][7] = {{0, 1, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 0, 0},
                  {0, 0, 0, 0, 0, 1, 1}, {0, 1, 0, 0, 0, 0, 0},
                  {0, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0},
                  {0, 0, 1, 0, 0, 0, 0}};

bool isVisited[7];

void DFS(int cur) {
    isVisited[cur] = true;
    cout << cur << ' ';

    for (auto i = 0; i < 7; i++) {
    if (isVisited[i] == true)
        continue;
    if (arr[cur][i] == false)
        continue;

    DFS(i);
    }
}

void BFS(int cur) {
    isVisited[cur] = true;
    deque<int> dq;
    dq.push_back(cur);

    while (!dq.empty() /*모든 노드를 순회하기 전까지 순회*/) {
        // 현재 노드는 큐에서 없애야현재 노드를 BFS로 순회할 수 있음.
        // 즉 now에 들어온다는 것은, now에 직접 연결되어있는 하위노드들을 순회
        int now = dq.front();
        cout << now << ' ';
        dq.pop_front();

        // now에 연결되어있는 모든 노드를 visit
        for (auto i = 0; i < 7; i++) {
        if (arr[now][i] == false)
            continue;
        if (isVisited[i] == true)
            continue;

            isVisited[i] = true;
            dq.push_back(i);
        }
    }
}

auto main() -> int {
    memset(isVisited, 0, sizeof(isVisited));
    cout << "DFS : ";
    DFS(0);

    memset(isVisited, 0, sizeof(isVisited));
    cout << "\nBFS : ";
    BFS(0);

    return 0;
}