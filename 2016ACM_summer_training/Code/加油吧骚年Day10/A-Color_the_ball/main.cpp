//2016.8.10
//树状数组，区间更新，单点查询
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int arr[100005], n;//arr[i]表示i管辖的范围内数字之和

int lowbit(int x){return x&(-x);}

int add(int pos, int tt)
{
	for(int i = pos; i <= n; i+=lowbit(i))
	  arr[i] += tt;
	return 0;
}

int query(int pos)
{
	int sum = 0; 
	for(int i = pos; i > 0; i-=lowbit(i))
	  sum+=arr[i];
	return sum;
}

int main()
{
	int a, b;
	while(cin>>n)
	{
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			add(a, 1);
			add(b+1, -1);
		}
		for(int i = 1; i <= n; i++)
		  if(i == n)
			cout<<query(i)<<endl;
		  else cout<<query(i)<<" ";
	}

	return 0;
}
