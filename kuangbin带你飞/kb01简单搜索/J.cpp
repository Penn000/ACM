//2017-03-01
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node{
	int x, y, step;
	void setNode(int x, int y, int step){
		this->x = x;
		this->y = y;
		this->step = step;
	}
};
char maze[1005][1005];
int dis[1005][1005], n, m;
bool vis[1005][1005];
const int inf = 0x3f3f3f3f;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};			

void bfs(int sx, int sy)
{
	queue<node> q;
	node tmp;
	memset(vis, 0, sizeof(vis));
	if(sx == -1){
		for(int i = 0; i < n; i++)
	  		for(int j = 0; j < m; j++)
		  		if(maze[i][j] == 'F')
				{
					tmp.setNode(i, j, 0);
					q.push(tmp);
					vis[i][j] = 1;
					dis[i][j] = 0;
				}
	}else{
		tmp.setNode(sx, sy, 0);
		q.push(tmp);
		vis[sx][sy] = 1;
	}
	int x, y, step, ans;
	bool fg = false;
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		step = q.front().step;
		q.pop();
		if(maze[sx][sy]=='J'&&(x == n-1 || y == m-1 || x == 0 || y == 0)){
			fg = true;
			ans = step+1;												
		}
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny]&&maze[nx][ny]!='#'){
				vis[nx][ny] = 1;
				if(maze[sx][sy]=='J'){
				  	if(step+1 >= dis[nx][ny])continue;
					else if(nx == n-1 || ny == m-1 || nx == 0 || ny == 0){
						fg = true;
						ans = step+2;
					}
				}else dis[nx][ny] = min(dis[nx][ny], step+1);
				tmp.setNode(nx, ny, step+1);
				q.push(tmp);
			}
		}
		if(fg)break;
	}
	if(maze[sx][sy] == 'J')
	  	if(fg)printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
}

int main()
{
	int T, jx, jy;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		getchar();
		for(int i = 0; i < n; i++){
		  	for(int j = 0; j < m; j++){
			  	scanf("%c", &maze[i][j]);
				if(maze[i][j] == 'J'){
					jx = i; jy = j;
				}
			}
			getchar();
		}
		memset(dis, inf, sizeof(dis));
		bfs(-1, -1);
		bfs(jx, jy);
	}

    return 0;
}
