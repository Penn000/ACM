//2017-05-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50005;
int e[N], n;

int lowbit(int x)
{
	return x&-x;
}

void add(int pos, int w)
{
	while(pos <= n){
		e[pos] += w;
		pos += lowbit(pos);
	}
}

int sum(int pos)
{
	int ans = 0;
	while(pos > 0){
		ans += e[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main()
{
    int T, a;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++){
		scanf("%d", &n);
		memset(e, 0, sizeof(e));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			add(i, a);
		}		  
		char op[10];
		int x, y;
		printf("Case %d:\n", kase);
		while(scanf("%s", op)){
			if(op[0] == 'Q'){
				scanf("%d%d", &x, &y);
				printf("%d\n", sum(y)-sum(x-1));
			}else if(op[0] == 'A'){
				scanf("%d%d", &x, &y);
				add(x, y);
			}else if(op[0] == 'S'){
				scanf("%d%d", &x, &y);
				add(x, -y);
			}else if(op[0] == 'E')
			  	break;
		}
	}

	return 0;
}
