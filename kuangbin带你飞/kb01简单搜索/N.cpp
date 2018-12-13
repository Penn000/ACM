//2017-02-28
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
char grid[205][205];
bool book[205][205];
int Ydis[205][205], Mdis[205][205];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const int inf = 0x3f3f3f3f;

void bfs(int sx, int sy)
{
	node tmp;
	tmp.setNode(sx, sy, 0);
	queue<node> q;
	q.push(tmp);
	memset(book, 0, sizeof(book));
	book[sx][sy] = 1;
	int x, y, step;
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		step = q.front().step;
		q.pop();
		if(grid[x][y] == '@'){
			if(grid[sx][sy] == 'Y')Ydis[x][y] = step;
			else Mdis[x][y] = step;
		}
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!book[nx][ny]&&grid[nx][ny]!='#'){
				book[nx][ny] = 1;
				tmp.setNode(nx, ny, step+1);
				q.push(tmp);
			}
		}
	}
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++)
			  	cin>>grid[i][j];
		memset(Ydis, inf, sizeof(Ydis));
		memset(Mdis, inf, sizeof(Mdis));
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++)
			  	if(grid[i][j] == 'Y' || grid[i][j] == 'M')
				  	bfs(i, j);
		int ans = inf;
		for(int i = 0; i < n; i++)
		  	for(int j = 0; j < m; j++)
			  	if(grid[i][j] == '@' && ans > Ydis[i][j]+Mdis[i][j])
				  	ans = Ydis[i][j] + Mdis[i][j];
		cout<<11*ans<<endl;
	}

    return 0;
}
