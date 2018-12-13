//2016.9.13
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 5005

using namespace std;

int a[N], arr[N], n;

int lowbit(int x){return x&(-x);}

void add(int pos, int tt)
{
	for(int i = pos; i <= n; i+=lowbit(i))
	  	arr[i] += tt;
}

int query(int pos)
{
	int sum = 0;
	for(int i = pos; i > 0; i-=lowbit(i))
	  	sum += arr[i];
	return sum;
}

int main()
{
	int sum, ans, tmp;
	while(scanf("%d", &n)!=EOF)
	{
		memset(arr, 0, sizeof(arr));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i];
		}
		sum = 0;
		for(int i = 1; i <= n; i++)
		{
			sum += query(n-a[i]);//n-a[i]表示a[i]为第n-a[i]大
			add(n-a[i], 1);
		}
		ans = sum;
		for(int i = 1; i < n; i++)
		{
			add(n-a[i], -1);
			sum = sum+query(n-a[i])-a[i];
			add(n-a[i], 1);
			if(ans > sum) ans = sum;
		}
		printf("%d\n", ans);
	}

    return 0;
}
