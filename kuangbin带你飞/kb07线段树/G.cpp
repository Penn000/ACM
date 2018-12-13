//2017-05-17
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 50005;
int a[N], DPmin[N][20], DPmax[N][20];

void init(int n)
{
	for(int j = 1; j<=(int)log2(n); j++)
	  for(int i = 1; i<=n; i++){
		  DPmax[i][j] = DPmax[i][j-1];
		  DPmin[i][j] = DPmin[i][j-1];
		  if(i+(1<<j)-1 <= n){
			  DPmax[i][j] = max(DPmax[i][j-1], DPmax[i+(1<<(j-1))][j-1]);
			  DPmin[i][j] = min(DPmin[i][j-1], DPmin[i+(1<<(j-1))][j-1]);
		  }
	  }
}

int query(int l, int r)
{
	int k = (int)log2(r-l+1);
	return max(DPmax[l][k], DPmax[r-(1<<k)+1][k])-min(DPmin[l][k], DPmin[r-(1<<k)+1][k]);
}

int main()
{
	int n, q;
	while(scanf("%d%d", &n, &q)!=EOF)
	{
		for(int i = 1; i <= n; i++){
			scanf("%d", &DPmax[i][0]);
			DPmin[i][0] = DPmax[i][0];
		}
		init(n);	
		int l, r;
		while(q--)
		{
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l, r));
		}
	}

	return 0;
}
