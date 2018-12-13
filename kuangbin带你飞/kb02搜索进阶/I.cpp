//2017-03-02
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node
{
	int level, x, y, step;
	void setNode(int l, int x, int y, int s){
		this->level = l;
		this->x = x;
		this->y = y;
		this->step = s;
	}
};
char maze[2][15][15];
bool vis[2][15][15];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	int C, T, n, m;
	cin>>C;
	while(C--)
	{
		cin>>n>>m>>T;
		node tmp;
		memset(vis, 0, sizeof(vis));
		queue<node> q;
		for(int level = 0; level < 2; level++)
		  	for(int i = 0; i < n; i++)
			  	for(int j = 0; j < m; j++){
				  	cin>>maze[level][i][j];
					if(maze[level][i][j]=='S'){
						tmp.setNode(level, i, j, 0);
						q.push(tmp);
						vis[level][i][j] = 1;
					}
				}
		int l, x, y, step, ans;
		bool fg = false;
		while(!q.empty())
		{
			l = q.front().level;
			x = q.front().x;
			y = q.front().y;
			step = q.front().step;
			if(step>T)break;
			q.pop();
			if(maze[l][x][y]=='P'){
				fg = true;
				break;																	
			}
			for(int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[l][nx][ny]&&maze[l][nx][ny]!='*')
				{
					if(maze[l][nx][ny]=='#'){
						if(maze[l^1][nx][ny]!='*' && maze[l^1][nx][ny]!='#'){
							vis[l][nx][ny] = 1;
							vis[l^1][nx][ny] = 1;
							tmp.setNode(l^1, nx, ny, step+1);
							q.push(tmp);
						}
					}else{
						vis[l][nx][ny] = 1;
						tmp.setNode(l, nx, ny, step+1);
						q.push(tmp);
					}
				}
			}
			if(fg)break;
		}
		if(fg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

    return 0;
}
