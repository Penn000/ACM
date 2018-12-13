//2016.8.18
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 405
#define lson (id<<1)
#define rson ((id<<1)|1)
#define mid ((r+l)>>1)

using namespace std;

struct node
{
	double l, r, y;
	int fg;
	bool operator<(node a) const
	{
		return y < a.y;
	}
}line[N*5];
int n, tim[N<<2];
double x[N<<2], sum[N<<2];

int bsearch(double a)
{
	int l = 0, r = n+1;
	while(r-l>1)
	{
		if(x[mid]<=a)l = mid;
		else r = mid;
	}
	return l;
}

void update(int a, int b, int l, int r, int id)
{
	if(l==r)
	{
		tim[a] += b;
		if(tim[a])sum[id] = x[a+1]-x[a];
		else sum[id] = 0;
		return ;
	}
	if(a<=mid) update(a, b, l, mid, lson);
	else update(a, b, mid+1, r, rson);
	sum[id] = sum[rson]+sum[lson];
	return ;
}

int main()
{
	int cnt, kase = 0;
	double ans = 0, x1, x2, y1, y2;
	while(cin>>n&&n)
	{
		cnt = 0; ans = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			int a = i*2-1, b = i*2;
			line[a].y=y1, line[a].l=x1, line[a].r=x2, line[a].fg=1;
			line[b].y=y2, line[b].l=x1, line[b].r=x2, line[b].fg=-1;
			x[++cnt] = x1, x[++cnt] = x2;
		}
		n*=2;
		sort(x+1, x+1+cnt);
		sort(line+1, line+1+n);
		memset(sum, 0, sizeof(sum));
		memset(tim, 0, sizeof(tim));
		for(int i = 1; i <= n; i++)
		{
			ans += sum[1]*(line[i].y-line[i-1].y);
			int l, r;
			l = bsearch(line[i].l);
			r = bsearch(line[i].r)-1;
			for(int j = l; j <= r; j++)
			  	update(j, line[i].fg, 1, n-1, 1);
		}
		printf("Test case #%d\n", ++kase);
		printf("Total explored area: %.2f\n\n", ans);
	}

	return 0; 
}
