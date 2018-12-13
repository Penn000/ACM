//2017-04-06
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
struct node{
	int l, r, h;
	bool operator<(const node x)
	{
		return this->h > x.h;
	}
}platform[1005];
int dpl[1005], dpr[1005];//dpl[i]记录从第i块平台左端点落地所需的最短时间,dpr[i]记录从第i块平台右端点落地所需的最短时间
int n, MAX;

int dfs(int x, int y, int ptr)//输入参数表示从第ptr块平台，位于(x, y)点开始搜索
{
	if(dpl[ptr] != inf && dpr[ptr] != inf)
	  if(y-platform[ptr].h <= MAX)
		if(platform[ptr].l <= x && platform[ptr].r >= x)
		  return y-platform[ptr].h+min(dpl[ptr]+x-platform[ptr].l, dpr[ptr]+platform[ptr].r-x);//记忆化搜索，返回位于(x, y)点向左右走的最短时间
	int l, r, h;
	for(int i = ptr; i < n; i++){
		l = platform[i].l;
		r = platform[i].r;
		h = platform[i].h;
		if(h <= y && y-h <= MAX){
			if(x >= l && x <= r){
				if(h == 0)return y-h;
				else{
					int left = dfs(l, h, i+1);//向左走
					dpl[i] = min(dpl[i], left);
					int right = dfs(r, h, i+1);//向右走
					dpr[i] = min(dpr[i], right);
					return y-h+min(dpl[i]+x-l, dpr[i]+r-x);
				}
			}
		}
	}
	return inf;
}

int main()
{
	int T, x, y, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &n, &x, &y, &MAX);		
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &platform[i].l, &platform[i].r, &platform[i].h);
			dpl[i] = dpr[i] = inf;
		}
		//加入地面这一块平台，高度为0，左右边界无穷
		platform[n].h = 0;
		platform[n].l = -inf;
		platform[n].r = inf;
		dpl[n] = dpr[n] = inf;
		n++;
		sort(platform, platform+n);
		int l, r, h, i;
		for(i = 0; i < n; i++)//找到下落遇到的地一块平台，从这块平台开始搜索
		{
			l = platform[i].l;
			r = platform[i].r;
			h = platform[i].h;
			if(h <= y && y-h <= MAX)
			  if(x >= l && x <= r)
				break;	
		}
		ans = dfs(x, h, i)+y-h;
		printf("%d\n", ans);
	}

	return 0;
}
