//2016.9.11
#include <iostream>
#include <cstdio>
#define N 20005

using namespace std;

int b[N];

int C(int m, int n)
{
	if(n-m < m)m = n-m;
	int ans = 1;
	for(int i = 0; i < m; i++)
	{
		ans *= n;
		n--;
	}
	for(int i = 2; i <= m; i++)
	  ans /= i;
	return ans;
}

int main()
{
	int m, n;
	while(scanf("%d", &m)!=EOF)
	{
		while(m--)
		{
			scanf("%d", &n);
			int sum = 0, max = 0;
			for(int i = 0; i < n; i++)
			{
				scanf("%d", &b[i]);
				sum += b[i];
				if(max<b[i])max = b[i];
			}
			int c = C(2, n);
			if(sum==2*c && max<=2*(n-1))
		  		printf("T\n");
			else printf("F\n");
		}
	}

    return 0;
}
