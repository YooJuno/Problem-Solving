#include <iostream>

using namespace std;

const int MAX_SIZE = 100001;

// 0으로 초기화
int arr[MAX_SIZE];                 // 원본 배열
long long segTree[MAX_SIZE * 4];  // 세그먼트 트리
long long lazyTree[MAX_SIZE * 4]; // lazy 트리 (지연 업데이트 저장)

// 세그먼트 트리 초기화
long long init(int node, int start, int end)
{
    if (start == end)
    {
        // 리프 노드일 경우, 원본 배열의 값을 그대로 저장
        return segTree[node] = arr[start];
    }

    int mid = (start + end) / 2;

    // 왼쪽 자식과 오른쪽 자식을 초기화한 뒤, 두 값을 더해서 저장
    return segTree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// lazy 값을 현재 노드에 반영하고 자식 노드에 전달
void propagate(int node, int start, int end)
{
    // 현재 노드에 아직 처리되지 않은(lazy한) 업데이트가 있다면
    if (lazyTree[node] != 0)
    {
        // 현재 노드의 구간 크기만큼 lazy 값을 곱해서 더함
        segTree[node] += (end - start + 1) * lazyTree[node];

        if (start != end)
        {
            // 리프 노드가 아니면, 자식에게 lazy 전달
            lazyTree[node * 2] += lazyTree[node];
            lazyTree[node * 2 + 1] += lazyTree[node];
        }

        // 이젠 레이지 하지 않으니까(일 다 했으니까) 해제
        lazyTree[node] = 0;
    }
}

// [left, right] 구간에 value를 더하는 함수
void update(int node, int start, int end, int left, int right, int value)
{
    // 먼저 lazy 처리
    propagate(node, start, end);

    if (end < left || right < start)
    {
        // 전혀 겹치지 않음
        return;
    }

    if (left <= start && end <= right)
    {
        // 현재 구간이 완전히 포함되는 경우
        segTree[node] += (end - start + 1) * value;

        if (start != end)
        {
            // 자식에게 lazy 값 전달
            lazyTree[node * 2] += value;
            lazyTree[node * 2 + 1] += value;
        }

        return;
    }

    // 일부 겹치는 경우, 자식에게 재귀적으로 업데이트
    int mid = (start + end) / 2;

    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);

    // 자식 노드의 값을 합산해서 부모 노드 갱신
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

// [left, right] 구간의 합을 구하는 함수
long long query(int node, int start, int end, int left, int right)
{
    // lazy 먼저 반영
    propagate(node, start, end);

    if (end < left || right < start)
    {
        // 전혀 겹치지 않음
        return 0;
    }

    if (left <= start && end <= right)
    {
        // 현재 구간이 완전히 포함됨
        return segTree[node];
    }

    // 일부 겹치는 경우, 자식 노드에 재귀적으로 쿼리
    int mid = (start + end) / 2;

    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 예시 데이터
    int n = 5;
    for(auto i = 1; i <= 5; i++)
    {
        arr[i] = i;
    }

    // 트리 초기화 (1~n)
    init(1, 1, n);

    // 구간 [2,4]에 +3
    update(1, 1, n, 2, 4, 3);

    // 구간 [1,5] 합 출력
    cout << query(1, 1, n, 1, 5) << '\n'; // 결과: 1+(2+3)+(3+3)+(4+3)+5 = 27

    return 0;
}
