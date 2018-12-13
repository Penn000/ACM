//2017-08-06
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 60;
int fa[N], arr[N];
long long pow[N];

void init(){
	pow[0] = 1;
	for(int i = 1; i < N; i++){
	  	fa[i] = i;
		pow[i] = pow[i-1]*2;
	}
}

int getfa(int x){
	if(fa[x] == x)return x;
	return fa[x] = getfa(fa[x]);
}

void Merge(int a, int b){
	int af = getfa(a);
	int bf = getfa(b);
	if(af != bf){
		fa[bf] = af;
	}
}

int main()
{
    int n, m, a, b;
	while(scanf("%d%d", &n, &m)!=EOF){
		init();
		while(m--){
			scanf("%d%d", &a, &b);
			Merge(a, b);
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		  	if(fa[i] == i)cnt++;
		if(m == 0)printf("1\n");
		else printf("%lld\n", pow[n-cnt]);
	}

	return 0;
}
