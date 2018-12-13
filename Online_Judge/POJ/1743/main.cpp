//2016.10.12
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20005;
const int inf = 0x3f3f3f3f;
int sa[N], wa[N], wb[N], wv[N], wss[N], Rank[N], height[N];

int cmp(int *r, int a, int b, int len)
{
	return r[a]==r[b] && r[a+len]==r[b+len];
}

void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for(i = 0; i < m; i++)wss[i] = 0;
	for(i = 0; i < n; i++)wss[x[i]=r[i]]++;
	for(i = 0; i < m; i++)wss[i]+=wss[i-1];
	for(i = n-1; i >= 0; i--)sa[--wss[x[i]]]=i;
	for(j = 1, p = 1; p < n; j *= 2, m = p){
		for(p = 0, i = n-j; i < n; i++)
		  	y[p++] = i;
		for(i = 0; i < n; i++)
		  	if(sa[i] >= j)
			  	y[p++] = sa[i]-j;
		for(i = 0; i < n; i++)
		  	wv[i] = x[y[i]];
		for(i = 0; i < m; i++)
		  	wss[i] = 0;
		for(i = 0; i < n; i++)
		  	wss[wv[i]]++;
		for(i = 1; i < m; i++)
		  	wss[i] += wss[i-1];
		for(i = n-1; i >= 0; i--)
		  	sa[--wss[wv[i]]] = y[i];
		for(t = x, x = y, y = t, p = 1, x[sa[0]]=0, i = 1; i < n; i++)
		  	x[sa[i]] = cmp(y, sa[i-1], sa[i], j)?p-1:p++;
	}
}

void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for(i = 1; i <= n; i++)Rank[sa[i]] = i;
	for(i = 0; i < n; height[Rank[i++]] = k)
	  	for(k?k--:0, j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++)
		  ;
}

int n, r[N], arr[N];

bool haveTheme(int len)
{
	int minn = inf, maxn = -inf;
	for(int i = 1; i <= n; i++){
		if(height[i] < len){
			if(maxn-minn >= len)
			  	return true;
			minn = inf; maxn = -inf;
		}
		minn = min(minn, sa[i]);
		maxn = max(maxn, sa[i]);
		if(i==n && maxn-minn >= len)
		  	return true;
	}
	return false;
}

int main()
{
	while(scanf("%d", &n)!=EOF && n)
	{
		int maxn = 0;
		for(int i = 0; i < n; i++)
		  	scanf("%d", &arr[i]);
		n--;
		for(int i = 0; i < n; i++)
		  	r[i] = arr[i+1]-arr[i] + 90;
		r[n] = 0;
		da(r, sa, n+1, 200);
		calheight(r, sa, n);
		int l = 3, r = n, mid, ans;
		while(l <= r){
			mid = (l+r)>>1;
			if(haveTheme(mid)){
				l = mid + 1;
				ans = mid;
			}else r = mid-1;
		}
		if(n < 9 || ans < 4)printf("0\n");
		else printf("%d\n", ans+1);
	}

    return 0;
}
