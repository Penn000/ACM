//2017-08-18
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int N = 20;
const int P = 12;
const int inf = 0x3f3f3f3f;
struct Node{
    int x, y, step, state;
    void setNode(int a, int b, int c, int d){
        x = a; y = b; step = c; state = d;
    }
};
//vis[x][y][state]记录该状态是否走过，edge[x1*100+y1][x2*100+y2]记录格子(x1,y1)和(x2,y2)之间关系(门、墙、路)，grid[x][y]记录(x,y)格子的钥匙，因为钥匙可以有多把，所以压缩成二进制。
int vis[N][N][1 << P], n, m, p, k, s, edge[2050][2050], grid[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(){
    queue<Node> q;
    Node tmp;
	int state = 0;
	if(grid[1][1])state = state|grid[1][1];
    tmp.setNode(1, 1, 0, state);
    q.push(tmp);
    vis[1][1][0] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        int state = q.front().state;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny][state])
                continue;
            if (edge[nx * 100 + ny][x * 100 + y] == -1)//遇到墙不可走
                continue;
            if (edge[nx * 100 + ny][x * 100 + y] == 0 || ((1 << (edge[nx * 100 + ny][x * 100 + y] - 1)) & state) > 0)//路或有钥匙可走
            {
                if(nx == n && ny == m){
                    printf("%d\n", step+1);
                    return;
                }   
                if (grid[nx][ny])//拿钥匙
                {
                    tmp.setNode(nx, ny, step+1, state|grid[nx][ny]);
                    vis[nx][ny][state|grid[nx][ny]] = 1;
                }
                else
                {
                    tmp.setNode(nx, ny, step+1, state);
                    vis[nx][ny][state] = 1;
                }
                q.push(tmp);
            }
        }
    }
	printf("-1\n");
}

int main()
{
	//freopen("inputB.txt", "r", stdin);
    while (scanf("%d%d%d%d", &n, &m, &p, &k) != EOF)
    {
        memset(grid, 0, sizeof(grid));
        memset(edge, 0, sizeof(edge));
        memset(vis, 0, sizeof(vis));
        int x1, x2, y1, y2, g;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
            if (g == 0)g = -1;
            edge[x1 * 100 + y1][x2 * 100 + y2] = edge[x2 * 100 + y2][x1 * 100 + y1] = g;
        }
        scanf("%d", &s);
        for (int i = 0; i < s; i++)
        {
            scanf("%d%d%d", &x1, &y1, &g);
            grid[x1][y1] |= (1<<(g-1));
        }
        bfs();
    }
    return 0;
}
