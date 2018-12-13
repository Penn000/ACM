//2016.8.10
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 32005

using namespace std;

int n, x, y, arr[N], level[N];//arr[i]表示坐标为ｘ的点出现的次数，level[i]表示第i级星星的数目

int lowbit(int x){
	return x&(-x);
}

int add(int pos, int num)
{
	for(int i = pos; i <= N; i+=lowbit(i))
	  arr[i]+=num;
}

int query(int l)
{
	int sum = 0;
	for(int i = l; i > 0; i-=lowbit(i))
	  sum += arr[i];
	return sum;
}

int main()
{
	while(cin>>n)
	{
		memset(arr, 0, sizeof(arr));
		memset(level, 0, sizeof(level));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			level[query(x+1)]++;//因为x可以等于0，为防止出现死循环，将横坐标整体向右平移一格
			add(x+1, 1);
		}

		for(int i = 0; i < n; i++)
		  cout<<level[i]<<endl;
	}

	return 0;
}
