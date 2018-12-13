//2016.9.13
#include <iostream>
#include <cstdio>
#define N 105

using namespace std;

int main()
{
	int T, kase = 0, ans, n, a, b, len, l[N], r[N];
	scanf("%d", &T);
	while(T--)
	{
		int tmp = 0;
		ans = 0;//假设最初需要0点能量
		scanf("%d%d%d%d", &n, &a, &b, &len);
		l[0] = r[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
			tmp = tmp+b*(l[i]-r[i-1])-a*(r[i]-l[i]);
			if(ans > tmp)ans = tmp;//绝对值的最大值
		}
		printf("Case #%d: %d\n", ++kase, -ans);
	}

    return 0;
}
