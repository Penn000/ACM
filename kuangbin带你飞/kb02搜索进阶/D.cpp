//2017-03-09
#include <iostream>
#include <cstdio>
#include <cstring>
#include  <queue>

using namespace std;

const int N = 105;
int grid[N][N];
bool vis[N][N][1005];
int n, m, k, d, ans;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {1, 0, -1, 0, 0};
struct castle
{
	char dir;
	int t, v;
}cas[N];
struct node
{
	int x, y, step;
	void setNode(short x, short y, short step)
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
			if(cas[grid[x][i]].dir == 'E' && (y-i)%cas[grid[x][i]].v == 0 && (Time-(y-i)/cas[grid[x][i]].v)>=0 && (Time-(y-i)/cas[grid[x][i]].v)%cas[grid[x][i]].t == 0)
			  return false;
		}
		if(grid[x][i])break;
	}
	for(int i = y+1; i <= m; i++){
		if(grid[x][i])
		  if(cas[grid[x][i]].dir == 'W' && (i-y)%cas[grid[x][i]].v == 0 && (Time-(i-y)/cas[grid[x][i]].v)>=0 && (Time-(i-y)/cas[grid[x][i]].v)%cas[grid[x][i]].t == 0)
			return false;
		if(grid[x][i])break;
	}

	for(int i = x-1; i >= 0; i--){
	  if(grid[i][y])
		if(cas[grid[i][y]].dir == 'S' && (x-i)%cas[grid[i][y]].v == 0 && (Time-(x-i)/cas[grid[i][y]].v)>=0 && (Time-(x-i)/cas[grid[i][y]].v)%cas[grid[i][y]].t == 0)
		  return false;
	  if(grid[i][y])break;
	}
	for(int i = x+1; i <= n; i++){
	  if(grid[i][y])
		if(cas[grid[i][y]].dir == 'N' && (i-x)%cas[grid[i][y]].v == 0 && (Time-(i-x)/cas[grid[i][y]].v)>=0 && (Time-(i-x)/cas[grid[i][y]].v)%cas[grid[i][y]].t == 0)
		  return false;
	  if(grid[i][y])break;
	}
	return true;
}

bool bfs()
{
	node tmp;
	queue<node> q;
	memset(vis, 0, sizeof(vis));
	vis[0][0][0] = 1;
	tmp.setNode(0, 0, 0);
	q.push(tmp);
	int x, y, nx, ny, step;
	if(grid[n][m])return false;
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		step = q.front().step;
		if(step>d)return false;
		q.pop();
		for(int i = 0; i < 5; i++)
		{
			nx = x+dx[i];
			ny = y+dy[i];
			if(nx>=0&&nx<=n&&ny>=0&&ny<=m&&!grid[nx][ny]&&!vis[nx][ny][step+1]&&judge(nx, ny, step+1)&&step+1<=d)
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
	while(scanf("%d%d%d%d", &n, &m, &k, &d)!=EOF)
	{
		int x, y;
		char ch[3];
		memset(grid, 0, sizeof(grid));
		for(int i = 1; i <= k; i++)
		{
			scanf("%s%d%d%d%d", ch, &cas[i].t, &cas[i].v, &x, &y);
			cas[i].dir = ch[0];
			grid[x][y] = i;
		}
		if(bfs())printf("%d\n", ans);
		else printf("Bad luck!\n");
	}

	return 0;
}