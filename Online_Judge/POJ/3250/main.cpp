//2016.8.23
#include<cstdio>

const int N = 80005;
int Stack[N], hi, top;

int main()
{
	int n;
	long long ans;
	while(scanf("%d", &n)!=EOF)
	{
		ans = top = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &hi);
			while(top>0&&Stack[top-1]<=hi)top--;//前开后闭原则
			ans += top;
			Stack[top++] = hi;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
