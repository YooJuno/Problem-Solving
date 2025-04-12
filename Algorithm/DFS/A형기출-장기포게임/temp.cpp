#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define MAX_SIZE 51

int N;
int MAP[MAX_SIZE][MAX_SIZE];
int states[MAX_SIZE][MAX_SIZE];
//int visited[MAX_SIZE][MAX_SIZE];
int levels[MAX_SIZE][MAX_SIZE];
int result = 0;
int py = 0, px = 0;
int move_flag = 0;
int attack_flag = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int results[2 * MAX_SIZE][2];
int idx_for_results = 0;

void init();
void input();
void dfs(int lev, int y, int x);
int is_none(int y, int x, int direction);

int main(void)
{
    freopen("sample_input.txt", "r", stdin);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        dfs(0, py, px);

        std::cout << "#" << tc << " " << result << "\n";
    }

    return 0;
}

void init()
{
    memset(MAP, 0x00, sizeof(MAP));
    memset(states, 0x00, sizeof(states));
    //memset(visited, 0x00, sizeof(visited));
    memset(levels, -1, sizeof(levels));
    result = 0;
    py = 0, px = 0;
    move_flag = 0;
    attack_flag = 0;
    memset(results, 0x00, sizeof(results));
    idx_for_results = 0;
}

void input()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> MAP[i][j];

            if (MAP[i][j] == 2)
            {
                py = i;
                px = j;
                MAP[i][j] = 0;
            }
        }
    }
}

void dfs(int lev, int y, int x)
{
    // 종료
    if (lev == 3) {
        return;
    }

    if (y < 0 || x < 0 || y >= N || x >= N) { return; }

    int idx_for_arrives = 0;
    int arrive_pos[4 * MAX_SIZE][2];
    memset(arrive_pos, -1, sizeof(arrive_pos));
    int change_flag = 0;
    // 모든 경로에 관해 이동이 가능한 경로일 때 dfs
    for (int i = 0; i < 4; i++)
    {
        if (is_none(y, x, i)) { continue; }

        // 이동 경로에 첫 번째 1이 나오면 break
        int ny = y, nx = x;
        while (1)
        {
            ny += dy[i];
            nx += dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) { break; }

            if (MAP[ny][nx] == 1)
            {
                attack_flag = 1;
                break;
            }
        }

        // 이동 경로에서 첫 번째 1 위치부터 그 뒤로 갈 수 있는 지를 검사
        while (1)
        {
            ny += dy[i];
            nx += dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) { break; }

            if (MAP[ny][nx] == 0)
            {
                if (lev < 2) {
                    arrive_pos[idx_for_arrives][0] = ny;
                    arrive_pos[idx_for_arrives++][1] = nx;
                }
            }

            if (attack_flag && MAP[ny][nx] == 1)
            {
                arrive_pos[idx_for_arrives][0] = ny;
                arrive_pos[idx_for_arrives++][1] = nx;

                attack_flag = 0;
                MAP[ny][nx] = 0;

                if (states[ny][nx] == 0)
                {
                    states[ny][nx] = 1;
                    result += 1;
                    levels[ny][nx] = lev;
                    change_flag = 1;

                    results[idx_for_results][0] = ny;
                    results[idx_for_results++][1] = nx;
                }
                break;
            }
        }
        //attack_flag = 0;
    }

    for (int i = 0; i < idx_for_arrives; i++)
    {
        int y_val = arrive_pos[i][0];
        int x_val = arrive_pos[i][1];

        if (y_val == -1 || x_val == -1) { continue; }

        dfs(lev + 1, y_val, x_val);

        if (states[y_val][x_val] == 1)
        {
            MAP[y_val][x_val] = 1;
        }
    }
    if (levels[y][x] == lev)
    {
        states[y][x] = 0;
        levels[y][x] = -1;
    }
    std::cout << "d";
}

int is_none(int y, int x, int direction)
{
    // 0: 이동 방향 모든 칸이 비어있지는 않음  => 갈 수 있음
    // 1: 이동 방향 모든 칸이 비어 있음 => 못 감
    while (1)
    {
        y += dy[direction];
        x += dx[direction];

        if (y < 0 || x < 0 || y >= N || x >= N) { break; }

        if (MAP[y][x] == 1) { return 0; }
    }

    return 1;
}