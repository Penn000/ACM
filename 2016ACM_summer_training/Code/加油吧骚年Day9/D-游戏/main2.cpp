//2016.8.23
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1000005;
int fa[N];
bool vis[N];

int getf(int a)
{
	if(a == fa[a]) return a;
	else return fa[a] = getf(fa[a]);
}

void mg(int a, int b)
{
	int af = getf(a);
	int bf = getf(b);
	if(af == bf) vis[af] = true;
	else{
		if(af < bf)swap(af, bf);
		vis[bf] = true;
		fa[bf] = af;
	}
}

int main()
{
	int n, a, b;
	memset(vis, false, sizeof(vis));
	scanf("%d", &n);
	for(int i = 1; i <= n+1; i++)
	  	fa[i] = i;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		mg(a, b);
	}

	for(int i = 1; i <= n+1; i++)
	  if(!vis[i]){
		  printf("%d\n", i-1);
		  break;
	  }

	return 0;
}
