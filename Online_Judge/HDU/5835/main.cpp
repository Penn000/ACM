//2016.8.16
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[15];

int main()
{
	int T, n, kase = 0, sum, mx, ans;
	cin>>T;
	while(T--)
	{
		sum = mx = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			if(mx<a[i])mx = a[i];
		}
		printf("Case #%d: ", ++kase);
		ans = min(sum/2, 2*(sum-mx)+1);
		printf("%d\n", ans);
	}

	return 0;
}
