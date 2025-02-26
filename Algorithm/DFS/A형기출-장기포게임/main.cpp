#include <iostream>

using namespace std;

enum Janggi
{
    JOL=1,
    PO
};

auto main() -> int
{
    freopen("sample_input.txt", "r", stdin);

    int T; cin >> T;
    for(auto test_case=1; test_case<=T; test_case++)
    {
        int result = 0;
        int N; cin >> N;

        int map[N][N];

        for(auto i = 0; i < N; i++)
        {
            for(auto j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
        }

        
        
        cout << '#' << test_case << ' ' << result << endl;
    }
    return 0;
}