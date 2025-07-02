// main.cpp
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT            (100)
#define CMD_ENTER      		(200)
#define CMD_LEAVE    		(300)
#define CMD_TRANSFORM       (400)

extern void init(int K, int L);
extern void enter(int mID, int mX, int mY, int mC);
extern void leave(int mID);
extern int transform(int mX, int mY);

static bool run()
{
    int Q;
    int K, L;
    int mID, mX, mY, mC;

    int ret = -1, ans;

    scanf("%d", &Q);

    bool okay = false;

    for (int q = 0; q < Q; ++q)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            scanf("%d %d", &K, &L);
            init(K, L);
            okay = true;
            break;
        case CMD_ENTER:
            scanf("%d %d %d %d", &mID, &mX, &mY, &mC);
            enter(mID, mX, mY, mC);
            break;
        case CMD_LEAVE:
            scanf("%d", &mID);
            leave(mID);
            break;
        case CMD_TRANSFORM:
            scanf("%d %d", &mX, &mY);
            ret = transform(mX, mY);
            scanf("%d", &ans);
            if (ret != ans)
                okay = false;
            break;
        default:
            okay = false;
            break;
        }
    }
    return okay;
}

int main()
{
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);

    int TC, MARK;

    scanf("%d %d", &TC, &MARK);
    for (int tc = 1; tc <= TC; ++tc)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}