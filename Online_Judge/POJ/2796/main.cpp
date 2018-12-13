//2016.8.23
#include<iostream>
#include<cstdio>
#define ll __int64

using namespace std;

const int N = 100005;
ll sum[N], ans, tmp;
int Stack[N], a[N], l[N], L, R;

int main()
{
	int n, top;
	while(scanf("%d", &n)!=EOF)
	{
		sum[0] = ans = top = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		a[++n] = -1;
		ans = -1;
		for(int i = 1; i <= n; i++)
		{
			if(top == 0 || a[i]>a[Stack[top-1]])
			{
				Stack[top++] = i;
				l[i] = i;
				continue;
			}
			if(a[i] == a[Stack[top-1]])continue;
			while(top>0 && a[i]<a[Stack[top-1]])
			{
				top--;
				tmp = 1ll*a[Stack[top]]*(sum[i-1]-sum[l[Stack[top]]-1]);
				if(tmp > ans)
				{
					ans = tmp;
					L = l[Stack[top]];
					R = i-1;
				}
			}

			l[i] = l[Stack[top]];
			Stack[top++] = i;
		}

		printf("%I64d\n%d %d\n", ans, L, R);
	}

	return 0;
}
