//2017-09-13
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11000;

int head[N], tot;
struct Edge{
	int v, w, next;
}edge[N<<1];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w){
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot++;
}

//down[u][0]表示u节点往下走的最大距离，down[u][1]表示节点u往下走的次大距离
//up[u]表示节点u往上走的最大距离，son[u]表示u节点往下走的最大距离对应的儿子
int n, down[N][2], up[N], son[N];

void dfs1(int u, int fa){
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v, w = edge[i].w;
		if(v == fa)continue;
		dfs1(v, u);
		if(down[v][0]+w > down[u][0]){//更新最大的情况
			down[u][1] = down[u][0];
			down[u][0] = down[v][0]+w;
			son[u] = v;
		}else if(down[v][0]+w > down[u][1])//只更新次大值的情况
		  	down[u][1] = down[v][0] + w;
	}
}

void dfs2(int u, int fa){
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].v, w = edge[i].w;
		if(v == fa)continue;
		if(son[u] != v)
			up[v] = max(up[u]+w, down[u][0]+w);
		else
			up[v] = max(up[u]+w, down[u][1]+w);
		dfs2(v, u);
	}
}

int main()
{
	//freopen("inputD.txt", "r", stdin);
	while(scanf("%d", &n) != EOF){
		init();
		int v, w;
		for(int i = 2; i <= n; i++){
			scanf("%d%d", &v, &w);
			add_edge(i, v, w);
			add_edge(v, i, w);
		}
		memset(up, 0, sizeof(up));
		memset(down, 0, sizeof(down));
		dfs1(1, 0);
		dfs2(1, 0);
		for(int i = 1; i <= n; i++)
		  	printf("%d\n", max(up[i], down[i][0]));
	}

	return 0;
}
