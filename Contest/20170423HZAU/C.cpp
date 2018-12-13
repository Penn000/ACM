#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 100005;
int n, depth5[N];
bool fg[N], vis[N];
vector<int> mat[N];

struct node
{
	int p, step;
};

void bfs(int x)
{
	memset(fg, 0, sizeof(fg));
	queue<node> q;
	fg[x] = 1;
	node tmp;
	tmp.p = x;
	tmp.step = 0;
	q.push(tmp);
	int ans = 0, p, step;
	while(!q.empty())
	{
		p = q.front().p;
		step = q.front().step;
		q.pop();
		if(step >= 6)break;
		int len = mat[p].size();
		for(int i = 0; i < len; i++)
		{
			if(vis[mat[p][i]]){

				continue;
			}
			if(!fg[mat[p][i]]){
				ans++;
				if(step < 5)depth5[x]++;
				fg[mat[p][i]] = 1;
				tmp.p = mat[p][i];
				tmp.step = step+1;
				q.push(tmp);
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++)
	{
		scanf("%d", &n);
		int u, v;
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d%d", &u, &v);
			mat[u].push_back(v);
			mat[v].push_back(u);
		}
		memset(depth5, 0, sizeof(depth5));
		memset(vis, 0, sizeof(vis));
		printf("Case #%d:\n", kase);
		for(int i = 1; i <= n; i++)
		  	bfs(i);
	}
	return 0;
}
