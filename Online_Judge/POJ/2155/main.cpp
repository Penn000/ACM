//2017-10-25
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100;

int bt[N][N], n, q;

int lowbit(int x){
	return x&(-x);
}

void add(int x, int y, int v){
	while(x <= n){
		int j = y;
		while(j <= n){
			bt[x][j] += v;
			j += lowbit(j);
		}
		x += lowbit(x);
	}
}

int sum(int x, int y){
	int sm = 0;
	while(x > 0){
		int j = y;
		while(j > 0){
			sm += bt[x][j];
			j -= lowbit(j);
		}
		x -= lowbit(x);
	}
	return sm;
}

int main()
{
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d", &n, &q);
		memset(bt, 0, sizeof(bt));
		char op;
		int x, y, x1, y1;
		while(q--){
			getchar();
			scanf("%c%d%d", &op, &x, &y);
			if(op == 'C'){
				scanf("%d%d", &x1, &y1);
				add(x, y, 1);
				add(x, y1+1, -1);
				add(x1+1, y, -1);
				add(x1+1, y1+1, 1);
			}else{
				printf("%d\n", sum(x, y)%2);
			}
		}
	}

	return 0;
}
