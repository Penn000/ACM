//2016.8.20
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int mp[1005][1005], book[1005][1005];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, x2, y2;
bool ok, fg;

void dfs(int x, int y, int pd, int tt)//pd表示上一次的方向,tt表示转折的次数
{
	if(tt>3)return ;
	if(x == x2 && y == y2)
	{
		cout << "YES" << endl;
		ok = true;
		return ;
	}
	if(x<1||x>n||y<1||y>m||mp[x][y]!=0)return;
	if(ok)return ;
	book[x][y] = 1;
	for(int i= 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(book[nx][ny]==1)continue;
		if(i != pd)
			dfs(nx, ny, i, tt+1);	
		else 
			dfs(nx, ny, i, tt);
		book[nx][ny] = 0;
	}
}
int main()
{
	int q, x1, y1;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)break;
		for(int i = 1; i <= n; i++)
		  	for(int j = 1; j <= m; j++)
			    scanf("%d", &mp[i][j]);
		  
		cin >> q;
		while(q--)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			memset(book, 0, sizeof(book));
			if(mp[x1][y1]==mp[x2][y2]&&mp[x1][y1]&&mp[x2][y2]&&x1>=1&&y1>=1&&x1<=n&&y1<=m&&x2>=1&&y2>=1&&x2<=n&&y2<=m)//剪枝
			{
				ok = false;
				int tmp = mp[x1][y1];
				mp[x1][y1] = 0;
				dfs(x1, y1, -1, 0);
				mp[x1][y1] = tmp;
				if(!ok)cout << "NO" << endl;
			}else
			{
				cout << "NO" <<endl;
			}
		}
	}

	return 0;
}
