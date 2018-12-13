//2016.8.11
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((l+r)>>1)
#define N 105
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

struct node{
	int min,lazy;
}tree[N*5];

const int inf = 0x3f3f3f3f;
int T[105][5005], F[105][5005], dp[105];

void push_up(int id)
{
	tree[id].min=min(tree[lson].min,tree[rson].min);
	return;
}

void build_tree(int id,int l,int r)
{
    tree[id].lazy = tree[id].min=inf;
	if (l==r)
	{
		return;										
	}
	build_tree(lson,l,mid);
	build_tree(rson,mid+1,r);
//	push_up(id);
	return;
}

void push_down(int id,int l,int r)
{
	if(tree[id].lazy!=inf){
	tree[lson].min=min(tree[lson].min, tree[id].lazy);
	tree[lson].lazy = min(tree[lson].lazy, tree[id].lazy);
	tree[rson].min = min(tree[rson].min, tree[id].lazy);
	tree[rson].lazy = min(tree[rson].lazy, tree[id].lazy);
	tree[id].lazy=inf;
	}
	return;
}

void ins(int id,int l,int r,int ql,int qr,int tt)
{
	if (ql<=l && r<=qr)
	{
		tree[id].min = min(tree[id].min, tt);
		tree[id].lazy = min(tree[id].lazy, tt);
		return;									
	}
	if (tree[id].lazy != inf) push_down(id,l,r);
	if (ql<=mid)
  		ins(lson,l,mid,ql,qr,tt);
	else if (mid+1<=qr)
  		ins(rson,mid+1,r,ql,qr,tt);
	else{
		ins(lson, l, mid, ql, mid, tt);
		ins(rson, mid+1, r, mid+1, qr, tt);
	}
	push_up(id);
	return;
}

int query(int id,int l,int r,int ql,int qr)
{
	if (ql<=l && r<=qr)
	{
		return tree[id].min;						
	}
	if (tree[id].lazy!=inf)
		push_down(id,l,r);
	int minnum = inf;
	if (ql<=mid)
  		minnum = min(minnum, query(lson,l,mid,ql,qr));
	if (mid+1<=qr)
  		minnum = min(minnum, query(rson,mid+1,r,ql,qr));
	return minnum;
}

int main()
{
	int n, m, l, r;
	while(scanf("%d%d", &n, &m)&&n&&m)
	{
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
			scanf("%d", &T[i][j]);
		for(int i = 1; i <= n; i++)
		  for(int j = 1; j <= m; j++)
			scanf("%d", &F[i][j]);
		
	//	memset(dp, 9999999, sizeof(dp));
		for(int i = 1; i <= m; i++)
		  dp[i] = T[1][i];
		for(int i = 1; i <= n-1; i++)
		{
			build_tree(1, 1, m);
			for(int j = 1; j <= m; j++)
			{
				l = max(1, j-F[i][j]);
				r = min(m, j+F[i][j]);
				ins(1, 1, m, l, r, dp[j]);
			}
			for(int j = 1; j <= m; j++)
			{
				l = max(1, j-F[i+1][j]);
				r = min(m, j+F[i+1][j]);
				dp[j] = query(1, 1, m, l, r)+T[i+1][j];
			}
		}
		int ans = dp[1];
		for(int i = 2; i <= m; i++)
		  if(ans>dp[i])
			ans = dp[i];
		printf("%d\n", ans);
	}

	return 0;
}
