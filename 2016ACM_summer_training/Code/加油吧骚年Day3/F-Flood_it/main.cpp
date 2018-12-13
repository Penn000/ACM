//2016.8.27
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//vis[i][j]为1表示格子与左上角连通,为2表示与连通块相邻的格子,0为其他
int a[10][10], vis[10][10], n, deep;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool ok;

int Astar()//估价函数，计算除左上角连通块之外还有多少颜色，即最少要染的次数
{
	int book[10], h = 0;
	memset(book, 0, sizeof(book));
	for(int i = 1; i <= n; i++)
	  	for(int j = 1; j <= n; j++)
		  	if(vis[i][j]!=1 && !book[a[i][j]])
			  	book[a[i][j]]++, h++;
	return h;
}

void dfs(int x, int y, int color)//把颜色为color的格子并入左上角连通块
{
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
		{
			if(vis[nx][ny] == 1)continue;
			vis[nx][ny] = 2;
			if(a[nx][ny] == color)
			  	dfs(nx, ny, color);
		}
	}
}

int fill(int color)//把vis[i][j]==2的格子染成color色
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	  	for(int j = 1; j <= n; j++)
		  	if(vis[i][j]==2&&a[i][j]==color)
			{
				cnt++;
				dfs(i, j, color);
			}
	return cnt;
}

void IDAstar(int step)
{
	if(ok)return ;
	int h = Astar();
	if(h == 0)
	{
		cout<<step<<endl;
		ok = true;
		return ;
	}
	if(step+h>deep)return ;
	int tmp[10][10];
	memcpy(tmp, vis, sizeof(tmp));
	for(int i = 0; i < 6; i++)//进行染色
	{
		if(fill(i)==0)continue;
		IDAstar(step+1);
		memcpy(vis, tmp, sizeof(vis));
	}
}

int main()
{
	while(scanf("%d", &n)!=EOF && n)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		ok = false;
		deep = 0;
		memset(vis, 0, sizeof(vis));
		dfs(1, 1, a[1][1]);//对左上角预处理
		while(!ok)
		{
			IDAstar(0);
			deep++;//一层一层加深搜索的深度
		}
	}

	return 0;
}
