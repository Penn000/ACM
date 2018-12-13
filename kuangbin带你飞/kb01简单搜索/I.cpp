//2017-02-28
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char grid[15][15], tmp[15][15];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int book[15][15], answer = 0x3f3f3f3f;
struct node
{
	int x, y, step;
};

void bfs(int n, int m, int x1, int y1, int x2, int y2)
{
	for(int i = 0; i < n; i++)
	  for(int j = 0; j < m; j++)
		tmp[i][j] = grid[i][j];
	int x, y, step, ans = 0;
	tmp[x1][y1] = '*';
	tmp[x2][y2] = '*';
	queue<node> q;
	node tmpnode;
	tmpnode.x = x1;
	tmpnode.y = y1;
	tmpnode.step = 0;
	q.push(tmpnode);
	tmpnode.x = x2;
	tmpnode.y = y2;
	q.push(tmpnode);
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		step = q.front().step;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&tmp[nx][ny]=='#')
			{
				tmpnode.x = nx;
				tmpnode.y = ny;
				tmpnode.step = step+1;
				ans = step+1;
				tmp[nx][ny] = '*';
				q.push(tmpnode);
			}
		}
		q.pop();
	}
	for(int i = 0; i < n; i++)
	  for(int j = 0; j < m; j++)
		if(tmp[i][j] == '#'){
			return;
		}
	if(ans < answer)answer = ans;
}

int main()
{
	int T, n, m, cnt;
	cin>>T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin>>n>>m;
		cnt = 0;
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
		  {
			  cin>>grid[i][j];
			  if(grid[i][j] == '#')cnt++;
		  }
		answer = 0x3f3f3f3f;
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++)
			{
				if(grid[i][j] == '#'){
					for(int i2 = i; i2 < n; i2++)
					  for(int j2 = 0; j2 < m; j2++){
						  if(i==i2 && j2 <= j)continue;
						  if(grid[i2][j2] == '#')bfs(n, m, i, j, i2, j2);
					  }
				}
			}
		if(answer == 0x3f3f3f3f)answer = -1;
		if(cnt==1)answer=0;
		cout<<"Case "<<kase<<": "<<answer<<endl;
	}
	return 0;
}
