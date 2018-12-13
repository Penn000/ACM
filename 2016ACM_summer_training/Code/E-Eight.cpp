#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>

using namespace std;

typedef long long LL;
char c;
int a[10][10],b[10],d[1000],deep,stx,sty;
char ans[4]={'u','d','l','r'};
bool ok=0;
map<int,bool> vis;
int fx[4]={-1,1,0,0};
int fy[4]={0,0,-1,1};

int Abs(int x)
{
	return x<0?-x:x;
}

bool solve()//求逆序对判断是否有解
{
	int ret=0;
	for
		ret++;
	}
	return !(ret%2);
}

int Astar()
{
	int h=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(a[i][j]!=0)
			{
				int tx=(a[i][j]-1)/3;
				int ty=(a[i][j]-1)%3;
				h+=(Abs(i-tx-1)+Abs(j-ty-1));
			}
	return h;
}

int zt()//把矩阵转换为int型数字
{
	int ztt=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			ztt=ztt*10+a[i][j];
		}
	return ztt;
}

void IDAstar(int x,int y,int step)
{
	if(ok)
	return;
	int h=Astar();
	if(!h && zt()==123456780)//找到答案
	{
		for(int i=0;i<step;i++)
			cout<<ans[d[i]];
		ok=1;
		cout<<endl;
		return;
	}
	if(step+h>deep)
	return;
	int now=zt();
	if(vis[now])
	return;
	vis[now]=1;
	for(int i=0;i<4;i++)
	{
		int nex=x+fx[i],ney=y+fy[i];
		if(nex>=1 && nex<=3 && ney>=1 && ney<=3)
		{
			d[step]=i;
			swap(a[x][y],a[nex][ney]);
			IDAstar(nex,ney,step+1);
			swap(a[x][y],a[nex][ney]);
			d[step]=0;
		}
	}
	return;
}

int main()
{
	char k;
	while(cin>>k) 
	{
		ok=0;
		deep=0;
		char c;
		for(int i=1;i<=9;i++)
		{
			if (i==1) c=k;
			else
				cin>>c;
			if(c=='x')
			b[i]=0;
			else
			b[i]=c-'0';
		}
		if(!solve())
		{
			cout<<"unsolvable"<<endl;
			continue;
		} 
		int ret=1;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				a[i][j]=b[ret];
				if(a[i][j]==0)
				{
					stx=i;
					sty=j;
				}
				ret++;
			} 
		while(!ok)
		{
			vis.clear();
			IDAstar(stx,sty,0);
			deep++;
		}
	}
	return 0;
}
