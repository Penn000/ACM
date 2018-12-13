#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct point
{
	int x, y, step;
};
const int N = 1e6+5;
int n, m, sx, sy, a, b;
bool book[N][N];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};

void bfs()
{
	int x, y, nx, ny, sp;
	queue<point> q;
	point tmp;
	tmp.x = sx;
	tmp.y = sy;
	tmp.step = 0;
	q.push(tmp);
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		sp = q.front().step;
		if((x==1&&y==1)||(x==1&&y==m)||(x==n&&y==1)||(x==n&&y==m))
		{
			printf("%d\n", q.front().step);
			return;
		}
		for(int i = 0; i < 4; i++)
		{
			nx = x + a*dx[i];
			ny = y + b*dy[i];
			if(nx>=1 && nx <= n && ny>=1 && ny <= m && book[nx][ny]==0)
			{
				tmp.x = nx;
				tmp.y = ny;
				tmp.step = sp+1;
				book[nx][ny] = 1;
				q.push(tmp);
			}
		}
		q.pop();
	}
	printf("Poor Inna and pony!\n");
	return;
}

int main()
{
	while(scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &a, &b) != EOF)
	{
		memset(book, 0, sizeof(book));
		bfs();
	}

    return 0;
}
