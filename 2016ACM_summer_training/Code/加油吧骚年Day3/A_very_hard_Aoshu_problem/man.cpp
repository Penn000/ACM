//2016.8.20
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 20
using namespace std;

int ans, num[N][N], n;//num[i][j]用来记录从i到j位，数字的大小。
char s[N];

void dfsR(int pos, int leftsum, int rightsum)
{
	if(pos == n && leftsum == rightsum){
		ans++; return;
	}
	if(leftsum < rightsum)return;//剪枝
	for(int i = pos; i < n; i++)
	  	dfsR(i+1, leftsum, rightsum+num[pos][i]);
}

void dfsL(int pos, int sum, int mid)//pos表示当前处理的位置,sum表示已处理的和,mid表示等号的位置。
{
	if(pos == mid)//对左边dfs完后，对右边dfs
	  	dfsR(mid, sum, 0);
	for(int i = pos; i < mid; i++)//枚举加号位置。
	  	dfsL(i+1, sum+num[pos][i], mid);
}
int main()
{
	while(scanf("%s", s)!=EOF)
	{
		if(s[0] == 'E')break;
		ans = 0;
		n = strlen(s);
		for(int i = 0; i < n; i++)
		{
			int tmp = 0;
			for(int j = i; j < n; j++)
			{
				tmp += s[j]-'0';
				num[i][j] = tmp;
				tmp *= 10;
			}
		}
//		for(int i = 0; i < n; i++)
//		{
//			for(int j = i; j < n; j++)
//			  cout<<num[i][j]<<" ";
//			cout<<endl;
//		}
		for(int i = 1; i < n; i++)//枚举等号的位置，然后暴搜
		  	dfsL(0, 0, i);
		cout<<ans<<endl;
	}

	return 0;
}
