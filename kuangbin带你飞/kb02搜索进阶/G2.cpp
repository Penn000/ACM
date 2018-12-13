//2017-03-08
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node 
{
	int x, y;
	void setNode(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
int n, m, zx[2], zy[2], ans, TIME;
char grid[850][850];
bool vis[2][850][850], ok;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<node> q[2];

bool judge(int x, int y)
{
	if(grid[x][y] == 'X')return false;
	for(int i = 0; i < 2; i++)
		if((abs(x-zx[i])+abs(y-zy[i]))<=2*TIME)
			return false;
	return true;
}

bool bfs(int id)
{
	int x, y, nx, ny, s;
	node tmp;
	s = q[id].size();
	while(s--)
	{
		x = q[id].front().x;
		y = q[id].front().y;
		q[id].pop();
		if(!judge(x, y))continue;
		for(int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&judge(nx, ny)&&!vis[id][nx][ny])
			{
				if(vis[id^1][nx][ny]){
					ok = true;
					return true;
				}
				vis[id][nx][ny] = 1;
				tmp.setNode(nx, ny);
				q[id].push(tmp);
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		node tmp;
		while(!q[0].empty())q[0].pop();
		while(!q[1].empty())q[1].pop();
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		getchar();
		for(int i = 0; i < n; i++)
		  	scanf("%s", grid[i]);
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(grid[i][j] == 'Z'){
					zx[cnt] = i;
					zy[cnt] = j;
					cnt++;
				}
				if(grid[i][j] == 'M'){
					tmp.setNode(i, j);
					vis[0][i][j] = 1;
					q[0].push(tmp);
				}
				if(grid[i][j] == 'G'){
					tmp.setNode(i, j);
					vis[1][i][j] = 1;
					q[1].push(tmp);
				}
			}
		}
		ok = false;
		TIME = 0;
		while(!q[0].empty() || !q[1].empty())
		{
			TIME++;
			if(bfs(0))break;
			if(bfs(0))break;
			if(bfs(0))break;
			if(bfs(1))break;
		}
		if(ok)printf("%d\n", TIME);
		else printf("-1\n");
	}
	return 0;
}
