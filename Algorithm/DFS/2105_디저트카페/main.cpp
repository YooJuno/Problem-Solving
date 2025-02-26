#include <iostream>

using namespace std;

bool visitedMenu[101];
bool visitedCafe[21][21];

// 뱡향 순서를 4개짜리 배열에 저장해야할 듯.(시계, 반시계 상관 없음)
// 메뉴 가짓 수와 카페위치에 대한 visited를 따로 선언해서 사용
// visited true를 만나면 바로 return으로 나오기.
// 직진할 것인가, 회전할 것인가... 회전 상태 저장해야할 듯.
// 맞은편 직선이 움직인 거리만큼 똑같이 가야함.
    // 즉 처음 두 직선의 경우의 수만 구하면 그 뒤는 알아서 돌리면 됨.
// now가 src가 될 때 까지 돌리고, 그 때 까지 모아온온 return cnt;

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = -1;
        
        int N; cin >> N;
        int cafe[N][N];
        for(auto i = 0; i < N; i++)
            for(auto j = 0; j < N; j++)
                cin >> cafe[i][j];        
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}