//2016.10.08
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int ans[30] = {0, 0, 0, 0, 1, 1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 10, 11, 12, 13, 14};
int main()
{
	int T, n, kase = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("Case #%d: %d\n", ++kase, ans[n]);
	}

    return 0;
}
