//2016.9.11
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005

using namespace std;

int a[N], nex[N];//nex数组，表示跳到下一个要取余的位置，比a[i]大的数不用取余，此处优化降低时间

int main()
{
	int T, n, q, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		scanf("%d", &q);
		int l, r;
		for(int i = 1; i <= n; i++)
		{
			nex[i] = -1;
			for(int j = i+1; j <= n; j++)
				if(a[i]>=a[j])
				{
					nex[i] = j;
					break;
				}
		}
		while(q--)
		{
			scanf("%d%d", &l, &r);
			ans = a[l];
			for(int i = nex[l]; i <= r; i = nex[i])
			{
				if(i == -1)break;
				ans %= a[i];
			}
			printf("%d\n", ans);
		}
	}

    return 0;
}
