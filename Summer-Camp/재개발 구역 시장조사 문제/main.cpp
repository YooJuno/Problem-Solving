// main.cpp
 
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
extern void init(int N, int mResidents[]);
extern int moveIn(int mId, int mNum);
extern int moveOut(int mId, int mNum);
extern int getCount(int sId, int eId);
extern int getDiff(int sId, int eId);
 
/////////////////////////////////////////////////////////////////////////
 
#define MAX_N 200000
#define CMD_INIT 100
#define CMD_MOVE_IN 200
#define CMD_MOVE_OUT 300
#define CMD_GET_COUNT 400
#define CMD_GET_DIFF 500
 
static int mResidents[MAX_N];
 
static bool run() {
    int q;
    scanf("%d", &q);
 
    int n, mId, mNum, sId, eId;
    int cmd, ans, ret = 0;
    bool okay = false;
 
    for (int i = 0; i < q; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
            case CMD_INIT:
                okay = true;
                scanf("%d", &n);
                for (int j = 0; j < n; ++j) {
                    scanf("%d", &mResidents[j]);
                }
                init(n, mResidents);
                break;
            case CMD_MOVE_IN:
                scanf("%d %d %d", &mId, &mNum, &ans);
                ret = moveIn(mId, mNum);
                if (ans != ret)
                    okay = false;
                break;
            case CMD_MOVE_OUT:
                scanf("%d %d %d", &mId, &mNum, &ans);
                ret = moveOut(mId, mNum);
                if (ans != ret)
                    okay = false;
                break;
            case CMD_GET_COUNT:
                scanf("%d %d %d", &sId, &eId, &ans);
                ret = getCount(sId, eId);
                if (ans != ret)
                    okay = false;
                break;
            case CMD_GET_DIFF:
                scanf("%d %d %d", &sId, &eId, &ans);
                ret = getDiff(sId, eId);
                if (ans != ret)
                    okay = false;
                break;
            default:
                okay = false;
                break;
        }
    }
    return okay;
}
 
int main() {
    setbuf(stdout, NULL);
    //freopen("sample_input.txt", "r", stdin);
 
    int T, MARK;
    scanf("%d %d", &T, &MARK);
 
    for (int tc = 1; tc <= T; tc++) {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
 
    return 0;
}