#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e4+5;
const int mod = 4073989;
int arr[N][N];

int loebit(int x)
{
	return -x&x;
}

void add(int x, int y, int tt)
{
	for(int i = x; i <= N; i+=lowbit(i))
	  for(int j = y; j <= N; j+=lowbit(i))
		arr[i][j] += tt;
}

int query(int x, int y)
{
	int sum = 0;
	for(int i = x; i > 0; i-=lowbit(i))
	  for(int j = y; j > 0; j-=lowbit(i))
		sum+=arr[i][j];
	return sum;
}

int main()
{
	int n, m, x, y, z, p;
	while(cin>>n&&n)
	{
		cin>>m;
		while(m--)
		{
			memset(arr, 0, sizeof(arr));
			scanf("%d%d%d%d", &p, &x, &y, &z);
			if(p==1)
			{
				add(x, y, z);
			}else
			{

			}
		}
	}
	return 0;
}
