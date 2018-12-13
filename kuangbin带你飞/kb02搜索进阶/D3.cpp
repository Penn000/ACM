#include <iostream>
#include <cstdio>
#include <cstring>
#include  <queue>

using namespace std;

const int N = 110;
int n, m, k, d, grid[N][N], ans;
bool vis[N][N][1005];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {1, 0, -1, 0, 0};
struct castle
{
	int dir, t, v;
}cas[N];
struct node
{
	int x, y, step;
	void setNode(int x, int y, int step)
	{
		this->x = x;
		this->y = y;
		this->step = step;
	}
};

bool judge(int x, int y, int Time)
{
	for(int i = y-1; i >= 0; i--)
	{
		if(grid[x][i]){
			if(cas[grid[x][i]].dir == 0 && (y-i)%cas[grid[x][i]].v == 0 && (Time-(y-i)/cas[grid[x][i]].v)>0 && (Time-(y-i)/cas[grid[x][i]].v)%cas[grid[x][i]].t == 0)
			  	return false;
		}
	}
	for(int i = y+1; i <= m; i++){
		if(grid[x][i])
			if(i > y && cas[grid[x][i]].dir == 2 && (i-y)%cas[grid[x][i]].v == 0 && (Time-(i-y)/cas[grid[x][i]].v)>0 && (Time-(i-y)/cas[grid[x][i]].v)%cas[grid[x][i]].t == 0)
			  	return false;
		}
	
	for(int i = x-1; i >= 0; i--)
		if(grid[i][y])
			if(cas[grid[i][y]].dir == 1 && (x-i)%cas[grid[i][y]].v == 0 && (Time-(x-i)/cas[grid[i][y]].v)>0 && (Time-(x-i)/cas[grid[i][y]].v)%cas[grid[i][y]].t == 0)
			  	return false;
	for(int i = x+1; i <= n; i++)
	  	if(grid[i][y])
			if(cas[grid[i][y]].dir == 3  && (i-x)%cas[grid[i][y]].v == 0 && (Time-(i-x)/cas[grid[i][y]].v)>0 && (Time-(i-x)/cas[grid[i][y]].v)%cas[grid[i][y]].t == 0)
			  	return false;
		
	
	return true;
}

bool bfs()
{
	node tmp;
	queue<node> q;
	tmp.setNode(0, 0, 0);
	q.push(tmp);
	judge(2, 0, 2);
	int x, y, nx, ny, step;
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		step = q.front().step;
		if(step+1>d)return false;
		q.pop();
		for(int i = 0; i < 5; i++)
		{
			nx = x+dx[i];
			ny = y+dy[i];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&!grid[nx][ny]&&!vis[nx][ny][step+1]&&judge(nx, ny, step+1))
			{
				if(nx==n&&ny==m){
					ans = step+1;
					return true;
				}
				vis[nx][ny][step+1] = 1;
				tmp.setNode(nx, ny, step+1);
				q.push(tmp);
			}
		}
	}
	return false;
}

int main()
{
	while(scanf("%d%d%d%d", &n, &m, &k, &d))
	{
		char ch;
		int x, y;
		memset(grid, 0, sizeof(grid));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= k; i++)
		{
			getchar();
			scanf("%c", &ch);
			switch(ch)
			{
				case 'E': cas[i].dir = 0;break;
				case 'S': cas[i].dir = 1;break;
				case 'W': cas[i].dir = 2;break;
				case 'N': cas[i].dir = 3;break;
			}
			scanf("%d%d%d%d", &cas[i].t, &cas[i].v, &x, &y);
			grid[x][y] = i;
		}
		vis[0][0][0] = 1;
		if(bfs())printf("%d\n", ans);
		else printf("Bad luck!\n");
	}

    return 0;
}
