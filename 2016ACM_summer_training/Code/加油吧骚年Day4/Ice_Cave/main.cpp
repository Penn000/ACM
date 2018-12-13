#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct node
{
	int x, y;
};
char m[505][505];
int vis[505][505];
int r, c, sx, sy, ex, ey;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool ok, fg;
void dfs(int x, int y)
{
	int nx, ny;
	if(fg)return ;
	if(x == ex && y == ey)
	{
		if(m[x][y]=='X')ok = true;
		else
		{
			int cnt = 0;
			for(int i = 0; i < 4; i++)
			{
				nx = x+dx[i];
				ny = y+dy[i];
				if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&m[nx][ny]=='.')
				  cnt++;
				if(cnt>=2)ok = true;
			}
		}
		fg = true;
		return ;
	}
	if(fg)return ;
	for(int i = 0; i < 4; i++)
	{
		nx = x+dx[i];
		ny = y+dy[i];
		if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&(m[nx][ny]=='.'||(nx==ex&&ny==ey))&&!vis[nx][ny])
		{
			vis[nx][ny] = 1;
			dfs(nx, ny);
			vis[nx][ny] = 0;
		}						  
	}
}

void bfs()
{
	queue<node> q;
	node tmp;
	tmp.x = sx; tmp.y = sy;
	q.push(tmp);
	while(!q.empty())
	{
		node ppp = q.front();
		q.pop();
		int x = ppp.x, y = ppp.y;
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx == ex && ny == ey)
			{
				if(m[nx][ny]=='X')ok = true;
				else
				{
					int cnt = 0;
					for(int i = 0; i < 4; i++)
					{
						int tx = nx+dx[i];
						int ty = ny+dy[i];
						if(tx>=1&&tx<=r&&ty>=1&&ty<=c&&m[tx][ty]=='.')
						  cnt++;
					}
					if(cnt>=2)ok = true;
				}
				fg = true;
			}
			if(fg)return;
			if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&m[nx][ny]=='.'&&!vis[nx][ny])
			{
				vis[nx][ny] = 1;
				ppp.x = nx; ppp.y = ny;
				q.push(ppp);
			} 							
		}
		if(fg)return;
	}
}

int main()
{
	while(cin>>r>>c)
	{
		fg = ok = false;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= r; i++)
		{
			getchar();
			for(int j = 1; j <= c; j++)
			{
				scanf("%c", &m[i][j]);
			}
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	//	dfs(sx, sy);
		bfs();
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
