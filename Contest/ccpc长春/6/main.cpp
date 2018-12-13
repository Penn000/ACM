//2016.10.08
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int T, n, k, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		int tmp = -1;
		scanf("%d%d", &n, &k);
		printf("Case #%d:", ++kase);
		if(k == 1){
			for(int i = 1; i <= n; i++)
			  	printf(" %d", i);
		}else{
			if(k&1){
				printf(" %d %d", 2*k, k);
				for(int i = 2; i <= n; i++)
				{
					if(i == 2*k)continue;
					if(i == k)printf(" 1");
					else printf(" %d", i);
				}
			}else{
				printf(" %d %d", 2*k, k);
				for(int i = 1; i <= n; i++)
				{
					if(i == k || i == 2*k)continue;
					else printf(" %d", i);
				}
			}
		}
		printf("\n");
	}

    return 0;
}
