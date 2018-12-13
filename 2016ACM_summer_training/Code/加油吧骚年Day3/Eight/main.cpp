// 2016.8.25
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int a[10][10], b[10], d[1000], sx, sy, deep;
bool ok;
map<int, bool> vis;
char dir[4] = {'u', 'd', 'l', 'r'};
int dx[4] = {-1, 1, 0, 0};//分别对应上下左右四个方向
int dy[4] = {0, 0, -1, 1};

bool solve()//求逆序对判断是否有解，偶数有解，奇数无解
{
	int cnt = 0;
	for(int i = 1; i <= 9; i++)
	  for(int j = 0; j < i; j++)
		if(b[i] && b[j]>b[i])
		  cnt++;
	return !(cnt%2);
}

int Astar()//启发函数，假设每个数字可以从别的数字头上跨过去，计算到达自己应该到的位置所需要的步数，即计算该数到达其正确位置的曼哈顿距离，h为各点曼哈顿距离之和
{
	int h = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			if(a[i][j]!=0)
			{
				int nx = (a[i][j]-1)/3;
				int ny = (a[i][j]-1)%3;
				h += (abs(i-nx-1)+abs(j-ny-1));
			// }
	return h;
}

int toInt()//把矩阵转换为int型数字
{
	int res = 0;
	for(int i = 1; i <= 3; i++)
	  for(int j = 1; j <= 3; j++)
		res = res*10+a[i][j];
	return res;
}

void IDAstar(int x, int y, int step)
{
	if(ok)return ;
	int h = Astar();
	if(!h && toInt()==123456780)//找到答案
	{
		for(int i = 0; i < step; i++)
			cout<<dir[d[i]];
		cout<<endl;
		ok = 1;
		return ;
	}
	if(step+h>deep)return ;//现实＋理想<现状，则返回，IDA*最重要的剪枝
	int now = toInt();
	if(vis[now])return ;//如果状态已经搜过了，剪枝，避免重复搜索
	vis[now] = true;
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=1&&nx<=3&&ny>=1&&ny<=3)
		{
			d[step] = i;
			swap(a[x][y], a[nx][ny]);
			IDAstar(nx, ny, step+1);
			swap(a[x][y], a[nx][ny]);
			d[step] = 0;
		}
	}
	return;
}

int main()
{
	char ch;
	while(cin >> ch)
	{
		ok = false;
		deep = 0;
		int cnt = 0;
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				if(i==1&&j==1);
				else cin >> ch;
				if(ch == 'x')
				{
					a[i][j] = 0;
					sx = i;
					sy = j;
				}else
				  a[i][j] = ch - '0';
				b[cnt++] = a[i][j];
			}
		}
		if(!solve())
		{
			cout<<"unsolvable"<<endl;
			continue;
		}
		while(!ok)
		{
			vis.clear();
			IDAstar(sx, sy, 0);
			deep++;//一层一层增加搜索的深度
		}
	}

	return 0;
}
