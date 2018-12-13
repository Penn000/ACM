#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 405
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((l+r)>>1)

using namespace std;

struct node
{
	double up, down, x;
	int fg;
	bool operator<(node a)
	{
		return x < a.x;
	}
}line[N<<2];
double sum[N<<2], y[N<<2];
int n, tree[N<<2];

int bsearch(int k)
{
	int l = 0, r = n;
	while(r-l>1)
	{
		if(y[mid]<=k)l = mid;
		else r = mid;
	}
	return l;
}

void update(int id, int l, int r, int a, int fg)
{
	if(l == r)
	{
		tree[a] += fg;
		if(tree[a])sum[id] = y[a+1]-y[a];
		else sum[id] = 0;
		return;
	}
	if(a<=mid) update(lson, l, mid, a, fg);
	else update(rson, mid+1, r, a, fg);
	sum[id] = sum[lson]+sum[rson];
	return ;
}

int main()
{
	int cnt, kase = 0;
	double ans, x1, y1, x2, y2;
	while(scanf("%d", &n)!=EOF && n)
	{
		cnt = -1; ans = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			int a = i<<1, b = (i<<1)|1;
			line[a].down=y1,line[a].up=y2,line[a].x=x1,line[a].fg=1;
			line[b].down=y1,line[b].up=y2,line[b].x=x2,line[a].fg=-1;
			y[++cnt] = y1, y[++cnt] = y2;
		}
		n<<=1;
		memset(sum, 0, sizeof(sum));
		memset(tree, 0, sizeof(tree));
		sort(y, y+cnt);
		sort(line, line+n);
		for(int i = 0; i < n; i++)
		{
			ans += sum[0]*(line[i].x-line[i-1].x);
			int up = bsearch(line[i].up)-1;
			int down = bsearch(line[i].down);
			for(int j = down; j <= up; j++)
			  	update(0, 0, n-1, j, line[j].fg);
		}

		printf("Test case #%d\n", ++kase);
		printf("Total explored area: %.2f\n\n", ans);
	}

	return 0;
}
