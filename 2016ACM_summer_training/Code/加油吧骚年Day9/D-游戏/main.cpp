#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1000005;

struct node
{
	int a, b;
	bool operator<(node x)
	{
		if(a == x.a)return b < x.b;
		else return a < x.a;
	}
}arr[N];

int main()
{
	int n, now;
	while(scanf("%d", &n)!=EOF)
	{
		for(int i = 0; i < n; i++)
			scanf("%d%d", &arr[i].a, &arr[i].b);
		sort(arr, arr+n);
		now = 1;
		for(int i = 0; i < n; i++)
		{
			if(arr[i].a <= now)
			{
				if(arr[i].b == now+1)
				  	now += 2;
			}else break;
		}
		printf("%d\n", now);
	}

	return 0;
}
