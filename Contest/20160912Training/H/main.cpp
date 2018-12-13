//2016.9.12
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005

using namespace std;

int nu[N], book[N];

int main()
{
	long long ans;
	int T, kase = 0, q, mod, op;
	scanf("%d", &T);
	while(T--)
	{
		ans = 1;
		memset(book, true, sizeof(book));
		printf("Case #%d:\n", ++kase);
		scanf("%d%d", &q, &mod);
		for(int i = 1; i <= q; i++)
		{
			scanf("%d%d", &op, &nu[i]);
			if(op == 1)
			{
				ans *= nu[i];
				ans %= mod;
			}
			else 
			{
				book[nu[i]] = false;
				book[i] = false;
				ans = 1;
				for(int  j = 1; j < i; j++)
				{
					if(book[j])ans = (ans*nu[j])%mod;
				}
			}
			printf("%lld\n", ans);
		}
	}

    return 0;
}
