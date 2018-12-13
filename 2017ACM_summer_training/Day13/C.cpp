#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int head[N], tot;
struct Edge{
	int to, next, w;
}edge[N<<2];

void add_edge(int u, int v, int w){
	edge[tot].w = w;
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

int up[N], down[N], vis[N];

int dfs_down(int u){
	if(down[u])return down[u];
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v])continue;
		vis[v] = 1;
		down[u] = max(down[u], dfs_down(v)+edge[i].w);
	}
	return down[u];
}

int dfs_up(int u, int fa){
	if(up[u])return up[u];
	for(int i = head[fa]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(vis[v])continue;
		vis[v] = 1;
		up[u] = max(up[u], dfs_up(v, u)+edge[i].w);
	}
	up[u] = max(up[u], up[fa]);
	return up[u];
}

int main()
{
	freopen("input.txt", "r", stdin);
    int n;
	while(scanf("%d", &n)!=EOF){
		int u, v, w, son;
		init();
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &u, &v, &w);
			add_edge(u, v, w);
			add_edge(v, u, w);
			if(u == 1)son = v;
			if(v == 1)son = u;
		}
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		dfs_down(1);
		for(int i = 1; i <= n; i++)
		  	cout<<down[i]<<" ";
		cout<<endl;
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		dfs_up(son, 1);
		for(int i = 1; i <= n; i++)
		  	cout<<up[i]<<" ";
		cout<<endl;
	}

	return 0;
}
