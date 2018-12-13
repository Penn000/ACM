#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T, kase = 0;
	int a, b, c, d, k;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int ans = 0;
		int x = b/k;
		int y = d/k;
		if(x>y)swap(x, y);

		printf("Case %d: %d\n", ++kase, ans);
	}

	return 0;
}
