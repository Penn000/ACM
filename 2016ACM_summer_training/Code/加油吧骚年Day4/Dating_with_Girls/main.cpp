//2016.8.4
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

struct node
{
	int x, y, sec;
};
char m[105][105];
int vis[105][105][12];
int c, r, k, T, sx, sy, ex, ey;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs()
{
	node start;
	start.x = sx; start.y = sy; start.sec = 0;
	queue<node> q;
	q.push(start);
	vis[sx][sy][0] = 1;
	while(!q.empty())
	{
		node tmp = q.front();
		node in;
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = tmp.x+dx[i];
			int ny = tmp.y+dy[i];
			in.x = nx; in.y = ny; in.sec = tmp.sec+1;
			if(nx>=0&&nx<r&&ny>=0&&ny<c&&!vis[nx][ny][in.sec%k])
			{
				if(in.x == ex && in.y == ey)
				{
					cout<<in.sec<<endl;
					return;
				}
				if((tmp.sec+1)%k==0 || m[nx][ny]=='.' || m[nx][ny]=='Y')
				{
					q.push(in);
					vis[nx][ny][in.sec%k] = 1;
				}	
			}
		}
	}
	cout<<"Please give me another chance!"<<endl;
}

int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%d%d%d", &r, &c, &k);
		for(int i = 0; i < r; i++)
		{
			getchar();
			for(int j = 0; j < c; j++)
			{
				scanf("%c", &m[i][j]);
				if(m[i][j] == 'Y')
				{
					sx = i;
					sy = j;
				}
				if(m[i][j] == 'G')
				{
					ex = i;
					ey = j;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		bfs();
	}

	return 0;
}
