#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node 
{
	int x, y, step;
	void setNode(int x, int y, int step)
	{
		this->x = x;
		this->y = y;
		this->step = step;
	}
};
int n, m;
char grid[850][850];
int zx[12] = {-2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2};
int zy[12] = {0, -1, 0, 1, -2, -1, 1, 2, -1, 0, 1, 0};
int gx[4] = {0, 0, 1, -1};
int gy[4] = {1, -1, 0, 0};

void print()
{
	cout<<">>>"<<endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		  cout<<grid[i][j];
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		queue<node> qZ, qM, qG, q;
		node tmp;
		scanf("%d%d", &n, &m);
		getchar();
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%c", &grid[i][j]);
				if(grid[i][j] == 'Z'){
					tmp.setNode(i, j, 0);
					qZ.push(tmp);
				}
				if(grid[i][j] == 'M'){
					tmp.setNode(i, j, 0);
					qM.push(tmp);
				}
				if(grid[i][j] == 'G'){
					tmp.setNode(i, j, 0);
					qG.push(tmp);
				}
			}
			getchar();
		}
		int ans = -1, step, nx, ny, x, y;
		bool ok = false;
		while(!qZ.empty() && !qM.empty() && !qG.empty())
		{
			step = qZ.front().step;
			while(step == qZ.front().step)
			{
				x = qZ.front().x;
				y = qZ.front().y;
				for(int i = 0; i < 12; i++)
				{
					nx = x + zx[i];
					ny = y + zy[i];
					if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!='Z')
					{
						grid[nx][ny] = 'Z';
						tmp.setNode(nx, ny, step+1);
						qZ.push(tmp);
					}
				}
				qZ.pop();
			}
		//	cout<<1;
		//	print();
			step = qM.front().step;
			while(!qM.empty() && step == qM.front().step)
			{
				x = qM.front().x;
				y = qM.front().y;
				qM.pop();
				if(grid[x][y] != 'M')continue;
				while(!q.empty())q.pop();
				tmp.setNode(x, y, 0);
				q.push(tmp);
				int s;
				while(!q.empty() && q.front().step<3)
				{
					x = q.front().x;
					y = q.front().y;
					s = q.front().step;
					q.pop();
					for(int i = 0; i < 4; i++)
					{
						nx = x + gx[i];
						ny = y + gy[i];
						if(nx>=0&&nx<n&&ny>=0&&ny<m&&(grid[nx][ny]=='.'||grid[nx][ny]=='G'))
						{
							if(grid[nx][ny]=='G'){
								ans = step + 1;
								ok = true;
								break;
							}
							grid[nx][ny] = 'M';
							tmp.setNode(nx, ny, s+1);
							q.push(tmp);
						}
					}	
				}
			//	print();
				while(!q.empty())
				{
					if(q.front().step != 3){
						q.pop();
						continue;
					}
		//			cout<<q.size()<<endl;
					x = q.front().x;
					y = q.front().y;
		//			printf("(%d, %d -- %d)\n", x, y, step+1);
					tmp.setNode(x, y, step+1);
					qM.push(tmp);
					q.pop();
				}
			}
		//	cout<<2;
		//	print();
			if(ok)break;
			step = qG.front().step;
			while(!qG.empty() && step == qG.front().step)
			{
				x = qG.front().x;
				y = qG.front().y;
				qG.pop();
				if(grid[x][y] != 'G')continue;
				for(int i = 0; i < 4; i++)
				{
					nx = x + gx[i];
					ny = y + gy[i];
					if(nx>=0&&nx<n&&ny>=0&&ny<m&&(grid[nx][ny]=='.'||grid[nx][ny]=='M'))
					{
						if(grid[nx][ny]=='M'){
							ans = step + 1;
							ok = true;
							break;
						}
						grid[nx][ny] = 'G';
						tmp.setNode(nx, ny, step+1);
						qG.push(tmp);
					}
				}
			}
	//		cout<<3;
	//		print();
			if(ok)break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
