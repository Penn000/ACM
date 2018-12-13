#include <stdio.h>
#include <memory.h>
#define MAXIN 75
char board[MAXIN + 2][MAXIN + 2];    //定义矩形板
int minstep, w, h, to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};    //定义方向
bool mark[MAXIN + 2][MAXIN + 2];    //定义标记数组

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f)
{
    if(step > minstep) return;  //当前路径数大于minstep, 返回优化策略
    if(now_x == end_x && now_y == end_y)    //到达终点
    {
        if(minstep > step)    //更新最小路径数
            minstep = step;
        return;
    }

    for(int i = 0; i < 4; i ++)      //枚举下一步的方向
    {
        int x = now_x + to[i][0];   //得到新的位置
        int y = now_y + to[i][1];
        if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2)&& (((board[y][x] == ' ') && (mark[y][x] == false))||((x==end_x)&& (y == end_y) && (board[y][x] == 'X'))))
        {
            mark[y][x] = true; //如果新位置有效标记该位置
            //已经过上一步方向和当前方向相同,
            //则递归搜索时step不变, 否则step+1
            if(f == i)
                Search(x, y, end_x, end_y, step, i);
            else
                Search(x, y, end_x, end_y, step + 1, i);
            mark[y][x] = false;    //回溯, 该位置未曾走过
        }
    }
}


int main()
{
    int Boardnum = 0;
    while(scanf("%d %d", &w, &h))     //读入数据
        if(w == 0 && h == 0)break;
    Boardnum ++;
    printf("Board #%d:\n", Boardnum);
    int i, j;
    for (i = 0; i < MAXIN + 2; i ++)board[0][i] = board[i][0] = ' ';
    for(i = 1; i <= h; i ++)     //读入矩形板的布局
    {
        getchar();
        for(j = 1; j <= w; j ++)
            board[i][j] = getchar();
    }   //在矩形板最外层增加一圈格子
    for (i = 0; i <= w; i ++)
        board[h + 1][i + 1] = ' ';
    for (i = 0; i <= h; i ++)
        board[i + 1][w + 1] = ' ';
    {
        int begin_x, begin_y, end_x, end_y, cnt = 0;
        while(scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y)&& begin_x > 0)    //读入起点和终点
        {
            cnt++;
            minstep = 100000;    //初始化minstep为一个很大的值
            memset(mark, false, sizeof(mark));    //递归搜索
            Search(begin_x, begin_y, end_x, end_y, 0, -1);    //输出结果
            if(minstep < 100000)printf("Pair %d: %d segments.\n", cnt, minstep);
            else
                printf("Pair %d: impossible.\n", cnt);
        }
        printf("\n");
    }
    return 0;
}


