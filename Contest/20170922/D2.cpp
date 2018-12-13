#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#define ms(a,b) memset((a),(b),sizeof((a)))
using namespace std;
typedef long long LL;
const int INF = 2e9;
const LL LNF = 9e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+10;

//M为棋盘， pos_goal为目标状态的每个数字所在的位置， pos_goal[dig] = pos,
//即表明：在目标状态中，dig所在的位置为pos。pos_goal与M为两个互逆的数组。
int M[MAXN], pos_goal[MAXN];

int fac[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dir[4][2] = { 1,0, 0,-1, 0,1, -1,0 };
char op[4] = {'d', 'l', 'r', 'u'  };

int cantor(int s[])  //获得哈希函数值
{
    int sum = 0;
    for(int i = 0; i<9; i++)
    {
        int num = 0;
        for(int j = i+1; j<9; j++)
            if(s[j]<s[i]) num++;
        sum += num*fac[8-i];
    }
    return sum+1;
}

int dis_h(int s[])  //获得曼哈顿距离
{
    int dis = 0;
    for(int i = 0; i<9; i++)
    if(s[i]!=9)
    {
        int x = i/3, y = i%3;
        int xx = pos_goal[s[i]]/3, yy = pos_goal[s[i]]%3;   //此处须注意
        dis += abs(x-xx) + abs(y-yy);
    }
    return dis;
}

char path[100];
int kase,  nextd;
bool IDAstar(int loc, int depth, int pre, int limit)
{
    int h = dis_h(M);
    if(depth+h>limit)
    {
        nextd = min(nextd, depth+h);
        return false;
    }

    if(h==0)
    {
        path[depth] = '\0';
        printf("Case %d: %d\n", kase, depth);
        puts(path);
        return true;
    }

    int x = loc/3;
    int y = loc%3;
    for(int i = 0; i<4; i++)
    {
        if(i+pre==3) continue;  //方向与上一步相反， 剪枝
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(xx>=0 && xx<=2 && yy>=0 && yy<=2)
        {
            int tmploc = xx*3+yy;
            swap(M[loc], M[tmploc]);
            path[depth] = op[i];
            if(IDAstar(xx*3+yy, depth+1, i, limit))
                return true;
            swap(M[loc], M[xx*3+yy]);
        }
    }
    return false;
}

int main()
{
    int T;
    char str[50];
    scanf("%d",&T);
    for(kase = 1; kase<=T; kase++)
    {
        int loc;
        scanf("%s", str);
        for(int i = 0; i<9; i++)
        {
            if(str[i]=='X') M[i] = 9, loc = i;
            else  M[i] = str[i]-'0';
        }

        scanf("%s", str);
        for(int i = 0; i<9; i++)
        {
            if(str[i]=='X') pos_goal[9] = i;
            else pos_goal[str[i]-'0'] = i;
        }

        for(int limit = dis_h(M); ; limit = nextd)     //迭代加深搜
        {
            nextd = INF;
            if(IDAstar(loc, 0, INF, limit))
                break;
        }
    }
}
