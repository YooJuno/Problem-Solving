#include <iostream>
using namespace std;

// 높이가 4가 나온다면
// 최대 개수를 몇개로 해야할까 ? -> 2 ^ h 만큼
char tree[16];

void init() 
{
    tree[1] = 'A';
    tree[2] = 'B';
    tree[3] = 'C';
    tree[4] = 'D';
    tree[5] = 'E';
    tree[7] = 'F';
    tree[10] = 'G';
}

int dfs(int index) 
{
    // 1. 기저조건(종료조건, 언제까지 재귀가 돌아가야 하는가 ?)
    if (index > 15) return 0;

    // 5. 기저조건 가지치기
    if (tree[index] == 0) return 0;

    // 재귀호출 파트 (후보군들을 반복하면서 호출)
    // 2. 다음 재귀 호출 전(데이터 갱신, 저장, 경로 기록 등등)
    // 6. 가지치기
    // 3. 다음 재귀함수 호출
    // 4. 돌아왔을 때 작업
    int left = dfs(index * 2);      // 왼쪽 자식으로 이동
    int right = dfs(index * 2 + 1); // 오른쪽 자식으로 이동
    return left + right + 1;
}

int main() 
{
    init();
    int cnt = dfs(1);
    cout << cnt << endl;
    return 0;
}
