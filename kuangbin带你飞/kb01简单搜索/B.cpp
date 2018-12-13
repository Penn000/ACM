//2017-02-20
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int dx[6] = {0, 0, 1, 0, -1, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {1, 0, 0, 0, 0, -1};

struct node
{
	int x, y, z, step;
};

int main()
{
	int level, n, m;
	char dun[35][35][35];
	bool vis[35][35][35];
	node tmp;
	while(cin>>level>>n>>m)
	{
		if(level == 0 && n == 0 && m == 0)break;
		queue<node> q;
		memset(vis, 0, sizeof(vis));
		for(int k = 0; k < level; k++)
		  	for(int i = 0; i < n; i++)
			  	for(int j = 0; j < m; j++){
				  	cin>>dun[i][j][k];
					if(dun[i][j][k] == 'S'){
						tmp.x = i;
						tmp.y = j;
						tmp.z = k;
						tmp.step = 0;
						q.push(tmp);
						vis[i][j][k] = 1;
					}
				}
		int x, y, z, step, nx, ny, nz;
		bool ok = false;
		while(!q.empty())
		{
			x = q.front().x;
			y = q.front().y;
			z = q.front().z;
			step = q.front().step;
			for(int i = 0; i < 6; i++)
			{
				nx = x+dx[i];
				ny = y+dy[i];
				nz = z+dz[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&nz>=0&&nz<level&&!vis[nx][ny][nz])
				{
					if(dun[nx][ny][nz] == '.'){
						vis[nx][ny][nz] = 1;
						tmp.x = nx;
						tmp.y = ny;
						tmp.z = nz;
						tmp.step = step+1;
						q.push(tmp);
					}else if(dun[nx][ny][nz] == 'E'){
						ok = true;
						cout<<"Escaped in "<<step+1<<" minute(s)."<<endl;
						break;
					}
				}
			}
			if(ok)break;
			q.pop();
		}
		if(!ok)cout<<"Trapped!"<<endl;
	}

    return 0;
}
